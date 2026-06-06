inherit ROOM;

void create ()
{
  set ("short", "後山小徑");
  set ("long", @LONG
一條順著峭壁邊緣延伸的小徑，寬僅數尺，南邊即為萬丈深谷，道路
往西方延伸，你看到路旁立了個警告牌 (sign)!

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "牌子上寫著 :
仙劍禁地 ,非請勿進 !
",
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g6-9.c",
  "east" : "/open/gsword/room/g6-4",
]));
  set("objects",([
        "/open/gsword/npc/trainee-5.c":1,
  ]));

  setup();
}
void init()
{
add_action("do_search","search");
add_action("do_jump","jump");
}
int valid_leave(object me, string dir)
{
        if(dir=="west"&&present("down yua",environment(me)))
return notify_fail("張淡月擋在你身前 ,說道:你是文盲啊 ?看不懂國字喔!\n");
        return ::valid_leave(me,dir);
}
int do_search(string str)
{
  if (this_player()->query("fyan")!=8 || str!="深谷") return 0;
  tell_object(this_player(),"深谷中傳出陣陣劍氣...使你忍不住想像下跳去\n");
  this_player()->set("fyan",9);
  return 1;
}
int do_jump(string str)
{
 if (this_player()->query("fyan") !=9 || str!="深谷") return 0;
 tell_object(this_player(),"你往深谷一躍.不料你的輕功\不如你想像的好..你直墜山谷下");
 this_player()->receive_wound("kee",4500);
 tell_object(this_player(),"你耗盡身上所有內力，但並無法只助你下陷之力.....");
 this_player()->set("force",0);
this_player()->move("/open/gsword/room1/yan1.c");
return 1;
}
