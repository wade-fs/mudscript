// Room: /u/w/whatup/peach/river2
inherit ROOM;

void create ()
{
  set ("short", "峭壁");
  set ("long", @LONG
一條小溪，水並不深，但是在大霧之中仍然讓你提心吊膽，兩旁
高大且濃密的樹木，像是張牙舞爪的妖怪，一步步的向你逼近，越往
前行走，越是讓人感到害怕，漸漸的迷失方向感及時間感，彷彿你不
存在於這個世界上一樣。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wall1.c",
]));
  set("outdoors", "/u/b");

  setup();
}
void init()
{
	add_action("search","search");
}
int search(string arg)
{
	if(!arg) 
	{
		write("你覺得草叢(grass)有點怪怪的！\n");
		return 1;
	}
	if(arg == "grass" || arg == "草叢")
	{
		set("exits/enter",__DIR__"hole1.c");
		call_out((:delete,"exits/enter":),3);
		message_vision("草叢裡突然冒出一條路！\n",this_player());
		return 1;
	}
	else 
	{
		write("你要找什麼？\n");
		return 1;
	}
	return 1;
}
