#pragma once
#include "Card.h"
#include <vector>
#include <memory>
#include<iostream>

class Deck
{
public:
    Deck();                         
    void ShuffleDeck();            
    std::shared_ptr<Card> GiveCard(); 
    void InitiateDeck();            
    void PrintDeckRanks() const {
        for (const auto& card : m_cards) {
            std::cout << static_cast<int>(card->GetValue()) << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::shared_ptr<Card>> m_cards; 
};
