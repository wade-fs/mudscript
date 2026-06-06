inherit ROOM;

void create ()
{
	set("short","廚　房");
	set("long",@LONG
這裡就是老婦人烹煮的地方了，一陣陣的菜香味不斷的湧入你的
鼻腔內，儘管你已經飽腹，還是忍不住的想要吃上一口，可惜，當你
想偷捻一塊食物時，後面正有著一雙大眼盯著你，想也知道，就是那
位婦人...(感覺上有點恐怖...)你心理這麼想著...

桌上擺滿了食物。
LONG);
	set("no_fight", 1);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/woman":1,
]));
	set("exits",([
"north":__DIR__"b-06",
"west":__DIR__"b-07",
]));
	setup();
}

 
