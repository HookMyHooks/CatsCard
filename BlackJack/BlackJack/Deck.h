#pragma once
#include "Card.h"

#include <vector>
#include <memory>

class Deck
{
public:
    Deck();                         
            
    CardPtr GiveCard(); 

    Cards GetCards()const;

    void ShuffleDeck();

private:
    void InitiateDeck();

private:
    Cards m_cards; 
};
