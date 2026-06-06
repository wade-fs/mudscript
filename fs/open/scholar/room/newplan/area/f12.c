// Room: /u/s/sueplan/newplan/area/f12.c
inherit ROOM;

void create ()
{
  set ("short", "吟風閣");
  set ("long", @LONG
風徐徐吹來，將籠罩著的薄霧吹散，定眼一看，已來到了吟風閣門前
；看這宅第蒼松環抱難辨大小，一色的白牆灰瓦相當素雅，門口兩隻石獅
子張嘴微笑著，似乎也安於這隱世獨立般的情調；一走到了門口，一位丫
鬟正笑吟吟地擋住了你的去路，看來你可得依著規矩送上名帖才行。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"f13.c",
  "west" : __DIR__"f11",
]));
  set("outdoors", "/u/s");

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter")
  {
    if(me->query_mark("sixgod-plan") && me->query_temp("six_ask")<4)
    return notify_fail("這裡你是進不去的!!\n");
  }
  return 1;
}
