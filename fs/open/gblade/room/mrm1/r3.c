// Room: /u/m/moner/tree/room19.c
inherit ROOM;

void create ()
{
  set ("short", "囚室");
  set ("long", @LONG

這裡是天邪峰囚禁犯人的牢房，兒臂粗細的鐵桿內一對對陰森的眼
睛，滿怖殺意的凝視著你，你每踏出一步，心裡便寒寒的發毛著，牢籠內
並沒有哀嚎聲，反而是一片的寧靜才令人越害怕。牢房內來來回回的走動
著獄卒。

LONG);

  set("exits", ([ /* sizeof() == 1 */
"east":"/open/gblade/room/room22.c",
]));
  set("light_up", 1);
set("no_transmit", 1);
  setup();
}
void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object        me=this_player();
      int    query;
message_vision("$N找來找去終於發現一條往下的路。\n", me);
set("exits/down","/open/gblade/room/mrm1/r4.c");
  return 1;
}

int valid_leave(object me, string dir)
{
if(dir =="down")
    this_object()->delete("exits/down");
    return 1;
  if (this_object()->query("exits/"+dir)) return 1;
  else return 0;

 }
