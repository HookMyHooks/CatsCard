#pragma once
#include "ICard.h"
#include <vector>
#include <memory>

class Deck
{
public:
    Deck();                         
    void ShuffleDeck();            
    std::shared_ptr<ICard> GiveCard(); 
    void InitiateDeck();            


private:
    std::vector<std::shared_ptr<ICard>> m_cards; 
};
