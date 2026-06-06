inherit ROOM;

void create ()
{
  set ("short", "通幽曲徑");
  set ("long", @LONG

這是連接王宅正廳跟內院的庭園，你往前一望，只見白石峻嶒，或如鬼怪
，或似猛獸，縱橫拱立；上面苔癬斑駁，或著是藤蘿掩映，其中微露羊腸
小徑。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/b-guardian" : 2,
]));
  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"g2-3.c",
  "south" : __DIR__"g2-1.c",
]));

  setup();
}
int valid_leave(object me,string dir)
{
	if(dir=="west"&&present("guardian",environment(me)))
	{
	if(me->query_temp("weapon"))
	return notify_fail("銅刀護院擋住了你的去路 ,說道 :請勿帶武器進入王家內院 \n");
	}
	return 1;
}
