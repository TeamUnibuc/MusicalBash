#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int off_x, int off_y, Window::Type w_type) :
    size_x(sz_x),
    size_y(sz_y),
    g_off_x(off_x),
    g_off_y(off_y),
    type_(w_type),
    prev_state(Constants::State::W::None)
{
    w_view_.reset(sf::FloatRect(off_x, off_y, size_x, size_y));
}

int Window::GetWidth() const
{
    return size_x;
} 

int Window::GetHeight() const
{
    return size_y;
} 

void Window::setViewPort(const sf::FloatRect& viewRect)
{
    w_view_.setViewport(viewRect);
}

void Window::Render(sf::RenderWindow& rw, int offX, int offY)
{
    sf::Clock renderTime;

    for (auto ptr_el : element_list) {
        ptr_el->Render(rw, g_off_x + offX, g_off_y + offY);
    }

//     if (type_ == Type::Main) {
//         Logger::Get() << "Render Time Main: " << renderTime.getElapsedTime().asSeconds() << '\n';
//     }
}

void Window::Update(int offX, int offY)
{
    switch (type_)
    {
        case Type::Main : {
            MainController(offX + g_off_x, offY + g_off_y);
            return;
        }
        case Type::Side : {
            SideController(offX + g_off_x, offY + g_off_y);
            return;
        }
        case Type::Status : {
            StatusController(offX + g_off_x, offY + g_off_y);
            return;
        }
    }

    throw bad_behaviour("Controller not existent for this Window type!");
}

/// =============== Controllers =====================

void Window::MainController(int off_x, int off_y)
{
    namespace Kld = Knowledge;

    auto& app_state = Kld::State::curr_state;

    if (prev_state != app_state) {
        Logger::Get() << "INFO:  Prev State -  ";
        Logger::PrintEnum(prev_state);
        Logger::Get() << "\n";
    }

    switch (app_state)
    {  
    /// ==== Main ==================  Queue  ==========================
    /// Queue state holds two things: A textbox for displaying the name of the view (Music Queue)
    ///   And a Scrollable list for the song entries
    case Constants::State::W::Queue: {
        /// If change of state then create the TextBox and ScrollableList
        if (prev_state != app_state) {
            Logger::Get() << "INFO:  New  State -  Queue\n";

            element_list.clear();

            ViewsMain::CreateQueue(this, this);
        }

        /// Gasesc lista care tine entry-urile din queue
        SharedPtr<ScrollableList> scrl_ptr;

        for (auto p : element_list) 
            if (dynamic_cast<ScrollableList*>(&*p))
                scrl_ptr = std::dynamic_pointer_cast<ScrollableList>(p);
        scrl_ptr->ClearAllUiElements();

        /// Updatez view-list-ul
        ViewsMain::UpdateQueue(scrl_ptr, Kld::Daddy_Player->GetPlayingQueue());

        Kld::State::curr_state = Constants::State::W::Queue;
        
        app_state = Constants::State::W::Queue;
        break;
    }  
    ///// ======================= Main ============= Home ==============================
    ///// The Home state holds three columns of stuff: Random Albums, Random Playlists, Random Songs
    case Constants::State::W::Home :
    {
        if (prev_state != app_state) {
            Logger::Get() << "INFO:  New state -  Home\n";

            element_list.clear();

            ViewsMain::CreateHome(this, this);
        }

        app_state = Constants::State::W::Home;
        
        ViewsMain::UpdateHome(this, this);

        app_state = Constants::State::W::Home;
        break;
    }

    ///// ==================== Main ============== Playlist ======================  TO DO

    case Constants::State::W::Playlists : 
    {
        if (prev_state != app_state) {
                Logger::Get() << "INFO:  New state - Playists\n";
                
                element_list.clear();
                ViewsMain::CreatePlaylists(this, this);
        }

        SharedPtr<ScrollableList> scrl_ptr;

        for (auto p : element_list) 
            if (dynamic_cast<ScrollableList*>(&*p))
                scrl_ptr = std::dynamic_pointer_cast<ScrollableList>(p);
        scrl_ptr->ClearAllUiElements();

        // sf::Clock testclock;

        ViewsMain::UpdatePlaylists(scrl_ptr, Kld::Daddy_Player->getPlaylists());

        // Logger::Get() << "INFOO TIME:  " << testclock.getElapsedTime().asSeconds() << '\n';

        app_state = Constants::State::W::Playlists;
        break;
    }

    //// ====================== Main ============== Albums ======================

    case Constants::State::W::Albums :
    {
        if (prev_state != app_state) {
            Logger::Get() << "INFO:  New state - Albums\n";

            element_list.clear();
            ViewsMain::CreateAlbums(this, this);
        }

        SharedPtr<ScrollableList> scrl_ptr;

        for (auto p : element_list) 
            if (dynamic_cast<ScrollableList*>(&*p))
                scrl_ptr = std::dynamic_pointer_cast<ScrollableList>(p);
        scrl_ptr->ClearAllUiElements();

        ViewsMain::UpdateAlbums(scrl_ptr, Knowledge::Daddy_Player->getAlbums());

        app_state = Constants::State::W::Albums;
        break;
    }

    case Constants::State::W::ViewAlbum : 
    {
        if (prev_state != app_state) {
            Logger::Get() << "INFO:  New state - Specific Album\n";
            
            element_list.clear();
            ViewsMain::CreateSpecificAlbum(this, this);
        }

        SharedPtr<ScrollableList> scrl_ptr;

        for (auto p : element_list) 
            if (dynamic_cast<ScrollableList*>(&*p))
                scrl_ptr = std::dynamic_pointer_cast<ScrollableList>(p);
        scrl_ptr->ClearAllUiElements();

        ViewsMain::UpdateSpecificAlbum(scrl_ptr);

        app_state = Constants::State::W::ViewAlbum;
        break;
    }

    case Constants::State::W::ViewPlaylist : 
    {
        if (prev_state != app_state) {
                Logger::Get() << "INFO:  New state - Specific Playists\n";
                
                element_list.clear();
                ViewsMain::CreateSpecificPlaylist(this, this);
        }

        SharedPtr<ScrollableList> scrl_ptr;

        for (auto p : element_list) 
            if (dynamic_cast<ScrollableList*>(&*p))
                scrl_ptr = std::dynamic_pointer_cast<ScrollableList>(p);
        scrl_ptr->ClearAllUiElements();

        ViewsMain::UpdateSpecificPlaylist(scrl_ptr);

        app_state = Constants::State::W::ViewPlaylist;
        break;
    }

    case Constants::State::W::Import : 
    {
        Logger::Get() << "INFO:  The App wants state Import, but i don't have to update any view";
        break;
    }

    case Constants::State::W::Create :
    {
        Logger::Get() << "INFO:  The app wants state Create (playlist), but \n \
                          The Main Window Controller doesn't have to ask for a new view";
        break;
    }

    case Constants::State::W::None :
    {
        Logger::Get() << "WARNING:  The app wants state None, but \n \
                          The Main Window Controller doesn't have to ask for a new view. WHO DID THIS?";
        break;
    }

    }

    prev_state = app_state;

    /// Finally update the elements contained in this window
    for (auto p : element_list)
        p->Update(off_x, off_y);
}


void Window::SideController(int off_x, int off_y)
{
    for (auto ptr : element_list)
        ptr->Update(off_x, off_y);
}

void Window::StatusController(int off_x, int off_y)
{
    for (auto ptr : element_list)
        ptr->Update(off_x, off_y);
}

}