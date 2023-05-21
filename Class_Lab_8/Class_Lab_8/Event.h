#pragma once
const int evNothing = 0; //пустое событие
const int evMessage = 100; //непустое событие
const int cmAdd = 1; //добавить обьект в группу
const int cmDel = 2; //удалить обьект из группы
const int cmGet = 3; //вывести атрибут всх обьектов
const int cmShow = 4; //вывести всю группу
const int cmMake = 6; //создать группу
const int cmQuit = 101; //выход

//класс событие
struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};