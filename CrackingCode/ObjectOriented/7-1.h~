class Card {
public:
  enum Suit{
    CLUBS,
    SPADES,
    HEART,
    DIAMONDS
  };
  Card(int p, Suit s) {
    suit = s;
    point = p;

  }
  int getPoint(){ return point; }
  Suit getSuit(){ return suit; }
protected:
  int point;
  Suit suit;
};

class BlackJackCard : Card{

public:
  BlackJackCard(int p, Suit s) : Card(p, s){
  }
  int getPoint() {
    int p = Card::getPoint();
    if (p == 1) return 11;
    else if (p > 10) return 10;
    return p;
  }
};
