#include "v_views.hpp"

const int ViewsMain::kListWidthSimple  = 760 + 18;
const int ViewsMain::kListWidthButtons = 550;
const int ViewsMain::kListHeight       = 440; 
const int ViewsMain::kEntryHeight      = 66;

const std::pair<int,int> ViewsMain::kListPoz = {40, 50};


void ViewsMain::Home()
{

}

void ViewsMain::CreateQueue(std::vector<SharedPtr<UiElement>>& father_elem_list)
{
    auto txt_ptr = std::make_unique<TextBox>(
        5, 8, 700, 30, 1, "Current Queue"
    );

    father_elem_list.push_back(std::move(txt_ptr));

    auto lst_ptr = std::make_unique<ScrollableList>(
        kListWidthSimple, kListHeight
    );
    lst_ptr->SetPosition(kListPoz);

    father_elem_list.push_back(std::move(lst_ptr));
}

void ViewsMain::UpdateQueue(SharedPtr<ScrollableList> l_ptr, const std::vector<SharedPtr<PMusic>>& music_list)
{
    for (auto m_ptr : music_list) {
        auto entry_ptr = std::make_unique<MusicEntry>(
            kListWidthSimple, kEntryHeight, 
            Constants::kSideBtnIdle, Constants::kSideBtnHover,
            m_ptr
        );
        l_ptr->AddUiElement(std::move(entry_ptr));
    }
}