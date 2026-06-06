// Room: /u/m/moner/room/room3.c
inherit ROOM;

void create ()
{
  set ("short", "兵器室");
  set ("long", @LONG

這裡是魔刀的兵器室，牆上掛滿了刀、槍、劍、爪、等武器，倚牆處有一個兵器架
(shelf)，大大小小的刀刃散放其上，屋外射入了一絲的陽光，映照在兵器上懾懾生
威，令人望而生畏。
而生畏。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"shelf" : "一個堆滿兵器的架子，私乎可以推的樣子。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room4.c",
]));

  setup();
}

void init()
{
add_action ("do_push","push");
}

int do_push (string str)
{
  object        me;
   if (!str || (str != "shelf" && str != "兵器架"&& str != "架子"))
return notify_fail("哇咧．．沒事不要亂推！\n
");

  me = this_player();
    message_vision("地上突然出現一個洞，你來不及跳開便摔了下去!!\n", me);
    me->move(__DIR__"room5.c");
    tell_room(environment(me), sprintf ("%s像棵石頭般摔了下來 .\n",
        me->short()), me);
  return 1;
}
