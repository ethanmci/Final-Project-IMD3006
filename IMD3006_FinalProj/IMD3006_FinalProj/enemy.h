#pragma once
#include <string>
#include <vector>
using namespace std;
class Enemy
{
public:
	//placeholder art? we gotta keep the signatures if we use it
	string visuals[3] = {
	R"(
 .-.
(o o) boo!
| O \
 \   \
  `~~~'
)",
	R"(
      .-.
     (o.o)
      |=|
     __|__
   //.=|=.\\
  // .=|=. \\
  \\ .=|=. //
   \\(_=_)//
    (:| |:)
     || ||
     () ()
     || ||
     || ||
l42 ==' '==
)",
	R"(
                \||/
                |  @___oo
      /\  /\   / (__,,,,|
     ) /^\) ^\/ _)
     )   /^\/   _)
     )   _ /  / _)
 /\  )/\/ ||  | )_)
<  >      |(,,) )__)
 ||      /    \)___)\
 | \____(      )___) )___
  \______(_______;;; __;;;	
)"
	};

	string visualsDeadVar[3] = {
R"(
 .-.
(x x) boo!
| O \
 \   \
  `~~~'
)",
	R"(
      .-.
     (x.x)
      |=|
     __|__
   //.=|=.\\
  // .=|=. \\
  \\ .=|=. //
   \\(_=_)//
    (:| |:)
     || ||
     () ()
     || ||
     || ||
l42 ==' '==
)",
	R"(
                \||/
                |  X___oo
      /\  /\   / (__,,,,|
     ) /^\) ^\/ _)
     )   /^\/   _)
     )   _ /  / _)
 /\  )/\/ ||  | )_)
<  >      |(,,) )__)
 ||      /    \)___)\
 | \____(      )___) )___
  \______(_______;;; __;;;	
)"
	};
	string enemyTypes[3] = { "ghost", "skeleton", "dragon" };
	string selWord;
	vector<char> pastGuesses;
	int selEnemyType;
	bool dead;

	//functions
	string getVis();
	string getEnemyType();
	Enemy(string newWord);
	void update();
};

