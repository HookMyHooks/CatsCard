#pragma once
#include "Card.h"
#include <vector>
#include <memory>

class Deck
{
public:
    Deck();                         
    void ShuffleDeck();            
    std::shared_ptr<Card> GiveCard(); 
    void InitiateDeck();     

    std::vector<std::shared_ptr<Card>> GetCards()const;


private:
    std::vector<std::shared_ptr<Card>> m_cards; 
};
