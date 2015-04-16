#ifndef CALL_H
#define CALL_H

class Call {

public:
  enum Difficulty {
    EASY = 1,
    NORMAL = 2,
    HARD = 3
  };
  Call(Difficulty d) {
    difficulty = d;
  }
  Difficulty getDifficulty() {
    return difficulty;
  }

private:
  Difficulty difficulty;
};

#endif
