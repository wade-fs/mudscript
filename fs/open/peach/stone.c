// Room: /u/w/whatup/peach/stone
inherit ROOM;

void create ()
{
  set ("short", "桃木林中的大石頭");
  set ("long", @LONG
當你走靠近時，突然發現到他的大腿受了傷，行走似乎不方便。
而且你還發現到他臉上充滿著焦急的表情，熱心的你忍不住想問他發
生了什麼事(happen)。
LONG);


  set("outdoors", "/u/b");
  set("exits", ([ /* sizeof() == 1 */
  "back" : __DIR__"peach10.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man.c" : 1,
]));

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
		write("你聽到前方(pass)有怒罵聲！\n");
		return 1;
	}
	if(arg == "pass" || arg == "前方")
	{
		set("exits/pass",__DIR__"epeach.c");
		call_out((:delete,"exits/pass":),5);
		message_vision("前方突然冒出一條路！\n",this_player());
		return 1;
	}
	else 
	{
		write("你要找什麼？\n");
		return 1;
	}
	return 1;
}
