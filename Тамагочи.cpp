#include <iostream>
using namespace std;
class Critter
{
public:
    Critter(int hunger = 3, int boredom = 3);
    void Talk();
    void Eat(int food = 1);
    void Play(int fun = 1);
    void Beat(int why = 1);
    void Howhunger();
    void Dead();
    
private:
    int m_Beats;
    int m_Hunger;
    int m_Boredom;
    int GetMood() const;
    void PassTime(int time = 1);
    void BassTime(int time = -1);
};
Critter::Critter(int hunger, int boredom):
m_Hunger(hunger),
m_Boredom(boredom)
{}

    inline int Critter::GetMood() const
{
        return (m_Hunger + m_Boredom);
}

void Critter::Dead()
    {
    if (m_Hunger < 0)
        cout << "Твой тамагочи помер от голода" << endl;
    }
    



void Critter::Howhunger()
    {
        cout << "Тамагочи имеет " << m_Hunger << " очков голода и " << m_Boredom << " очков веселья";
    }
    


void Critter::BassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;

}
void Critter::PassTime(int time)
{
    m_Hunger += time; 
    m_Boredom += time;
    
  
}

void Critter::Talk()
{
    cout << " Я тамагочи и я чуствую себя: ";
    int mood = GetMood();
    if (mood > 15)
    {
        cout << "Щаслив.\n";
    }
    else if (mood > 10)
    {
        cout << "Норме.\n";
    }
    else if (mood > 5)
    {
        cout << "Злым.\n";
    }
    else if (mood > 1)
    {
        cout << "В дисперсии.\n";
    }
    else
    {
        cout << "Я умер блинб((((.\n";
        
    }
}

void Critter::Beat(int why)
{
    cout << "Зачем ты сделал это?\n";
    m_Beats -= why;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    else if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    else if (m_Beats < 0)
    {
        m_Beats = 0;
    }
    BassTime();

}

void Critter::Eat(int food)
{
    cout << "Weeeeee!.\n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Bruuuuuup!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Critter crit;
    int choice;
    cout << "\n---Тамагочи---\n\n";
    cout << "0 --- Выйти\n";
    cout << "1 --- Послушать тамагочи.\n";
    cout << "2 --- Поиграть с  тамагочи.\n";
    cout << "3 --- Покормить  тамагочи.\n";
    cout << "4 --- Узнать голод и скуку тамагочи на данный момент.\n";
    cout << "5 --- Ударить тамагочи.\n";
    
    do
    {
        cout << "\nВыбирай: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Пока!\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Howhunger();
            break;
        case 5:
            crit.Beat();
            break;       
        default:
            cout << "\nСорри но такого выбора: " << choice << " не существует.\n";
           
        }
    } while (choice != 0);
  
    return 0;
}
