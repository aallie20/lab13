#include "arcade.h"

#include <iostream>

Arcade::Arcade()
    : m_count(0) {
    for (int i = 0; i < max_games; ++i) {
        m_games[i] = nullptr;
    }
}

Arcade::~Arcade() {
    for (int i = 0; i < m_count; ++i) {
        delete m_games[i];
    }
}

void Arcade::add(Game *game) {
    if (m_count < max_games) {
        m_games[m_count] = game;
        ++m_count;
    } else {
        delete game;
    }
}

void Arcade::run() {
    while (true) {
        std::cout << "\n=== Arcade ===\n";

        for (int i = 0; i < m_count; ++i) {
            std::cout << (i + 1) << ". "
                      << m_games[i]->title() << '\n';
        }

        std::cout << "0. Quit\n";
        std::cout << "Choice: ";

        int choice;

        if (!(std::cin >> choice)) {
            return;
        }

        if (choice == 0) {
            return;
        }

        if (choice >= 1 && choice <= m_count) {
            m_games[choice - 1]->play();

            std::cout << "Score: "
                      << m_games[choice - 1]->last_score()
                      << '\n';
        }
    }
}
