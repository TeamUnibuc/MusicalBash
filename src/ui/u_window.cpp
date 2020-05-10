#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int off_x, int off_y, Window::Type w_type) :
    size_x(sz_x),
    size_y(sz_y),
    g_off_x(off_x),
    g_off_y(off_y),
    type_(w_type)
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
    for (auto ptr_el : element_list) {
        ptr_el->Render(rw, g_off_x + offX, g_off_y + offY);
    }
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

void Window::AddSampleUiElement(std::shared_ptr<UiElement> ptr)
{
    element_list.push_back(ptr);
}

void Window::ClearAllElements()
{
    element_list.clear();
}

/// =============== Controllers =====================

void Window::MainController(int off_x, int off_y)
{
    namespace Kld = Knowledge;

    switch (Knowledge::curr)
    {  /// ==== Main ==================  Queue  ==========================
    case Constants::State::W::Queue: {
        /// If change of state then create the TextBox and ScrollableList
        if (prev_state != Constants::State::W::Queue) {
            Logger::Get() << " | Prev State: ";
            Logger::PrintEnum(prev_state);
            Logger::Get() << "  New state:  Queue\n";

            element_list.clear();

            auto txt_ptr = std::make_unique<TextBox>(
                5, 5, 700, 30, 1, "Current Queue"
            );
            element_list.push_back(std::move(txt_ptr));

            auto lst_ptr = std::make_unique<ScrollableList>(
                700, 500
            );
            lst_ptr->SetPosition({5, 35});
            element_list.push_back(std::move(lst_ptr));

            Logger::Get() << " - Added A ScrList and a TextButton to Main window\n";
        }
        /// find the ScrollableList in elements_list
        SharedPtr<ScrollableList> ptr;
        // int dbg_cnt = 0;
        for (auto p : element_list) {
            if (dynamic_cast<ScrollableList*>(&*p)) {
                ptr = std::dynamic_pointer_cast<ScrollableList>(p);
                // ++dbg_cnt;
            }
        }
        // Logger::Get() << "Found  - " << dbg_cnt << " - ScrollableList elements in Container\n";

        Knowledge::curr = Constants::State::W::Queue;

        break;
    }  ///// ===== Main ============= Home =====================
    case Constants::State::W::Home :
    {
        if (prev_state != Constants::State::W::Home) {
            Logger::Get() << " | Prev State: ";
            Logger::PrintEnum(prev_state);
            Logger::Get() << "  New state:  Home\n";

            element_list.clear();
        
            #pragma region
        //   {
        //     // Lets add some list of objects!!
        //     const std::string play_str = "data/img/play_button.png";
        //     const std::string power_str = "data/img/power_button.png";
        //     SharedPtr<ScrollableList> my_scroll_list(new ScrollableList(550, 470));
        //     for (int i = 0;  i < 20;  ++i) {
        //         // SharedPtr<DummyUI> someDummy(new DummyUI(400 + rand() % 100, 10 + rand() % 20));
        //         SharedPtr<TextBox> someDummy(new TextBox(0, 0, 550, 40, 0, "Musical Bash"));
        //         if (i % 3 == 0){
        //             someDummy->SetColor(sf::Color::Blue);
        //             someDummy->SetAlignment(i % 3);
        //         }
        //         else if (i % 3 == 1) {
        //             someDummy->SetColor(sf::Color::Yellow);
        //             someDummy->SetAlignment(i % 3);
        //         }
        //         else {
        //             someDummy->SetColor(sf::Color::Red);
        //             someDummy->SetAlignment(i % 3);
        //         }
                
        //         my_scroll_list->AddUiElement(someDummy);
        //     }
        //     for (int i = 20; i < 40; ++i){
        //         SharedPtr<TextBox> someDummy(new TextBox(0, 0, 550, 40, 0, "The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly but gets faster each minute after you hear this signal bodeboop."));
        //         if (i % 3 == 0){
        //             someDummy->SetColor(sf::Color::Blue);
                    
        //         }
        //         else if (i % 3 == 1){
        //             someDummy->SetColor(sf::Color::Yellow);
        //             someDummy->SetAlignment(i % 3);
        //         }
        //         else{
        //             someDummy->SetColor(sf::Color::Red);
        //             someDummy->SetAlignment(i % 3);
        //         }
                
        //         my_scroll_list->AddUiElement(someDummy);
        //     }


        //     element_list.push_back(my_scroll_list);

        //     // SharedPtr<TextBox> my_text_box(new TextBox(0, 0, 550, 50, 0, "The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly but gets faster each minute after you hear this signal bodeboop. "));
        //     // SharedPtr<TextBox> my_text_box2(new TextBox(0, 50, 550, 50, 0, "Musical Bash"));
        //     // SharedPtr<TextBox> my_text_box3(new TextBox(0, 100, 550, 50, 1, "Musical Bash"));
        //     // SharedPtr<TextBox> my_text_box4(new TextBox(0, 150, 550, 50, 2, "Musical Bash"));

        //     // element_list.push_back(my_text_box);
        //     // element_list.push_back(my_text_box2);
        //     // element_list.push_back(my_text_box3);
        //     // element_list.push_back(my_text_box4);
        //   }
        #pragma endregion

        }

        Knowledge::curr = Constants::State::W::Home;

        for (auto p : element_list)
            p->Update(off_x, off_y);


        break;
    }

    /// Next case here

    }

    prev_state = Knowledge::curr;
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