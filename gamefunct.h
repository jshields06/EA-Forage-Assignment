#ifndef GAMEFUNCT
#define GAMEFUNCT
using namespace std;
#include <string>

class Menu
{
protected:
	int physical_impact = 1;
	int emotional_impact = 2;

public:
	int navigate();
	string user_input;
};

class Camera
{
protected:
	int full_body_view = 1;
	int face_view = 2;
public:
	int view_state = 0;
	int change_view(int z);
};

class EmotionalRegulation
{
protected:
	int pep_talk = 3;
public:
	int act();
};

class FacialChange
{
protected:
	string happy = "smiling";
	string neutral = "neither";

public:
	string sad = "frowning";
	string express(int w);
};

#endif // GAMEFUNCT