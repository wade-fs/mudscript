// Room: /open/scholar/room/backm1.c
inherit ROOM;

void create ()
{
  set ("short", "小屋入口");
  set ("long", @LONG
這裡是小屋的門口，有一個小童看守著這個小屋。要進去
好像要經過他的同意呢。
LONG);

  set("no_kill", 1);
  set("no_fight", 1);
  set("objects",([
        "/open/scholar/npc/boy3":1,
        ]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"backm4",
  "enter" : __DIR__"house",

]));

  setup();
}
int valid_leave(object who, string dir)
{
  if(userp(who))
  {
    if(dir == "enter" && present("small boy",this_object()) && who->query_temp("quests/confuse") < 4)
    {
      return notify_fail("小童大喝：沒有經過師父的同意，這裡不能進去。\n");
    }
    if(dir == "enter" &&  who->query_temp("quests/confuse") < 4) 
      return notify_fail("沒有經過師父的同意，你想還是不要隨便進去好了。\n");
  }
  return ::valid_leave(who, dir);
}


