// Room: /open/badman/room/r13

#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG
你順著香味的來源走了進來，原來這裡就是這家飯館的廚房，
令人驚訝的是，這裡的掌廚竟然是愛吃人肉出名的李大嘴，讓你不
禁要懷疑這裡賣的是什麼肉了。想到這裡，原本爐子上令人垂涎三
尺的香味也開始變得令人作噁，你忽然發現李大嘴正流著口水盯著
你猛看呢！識相的還是快溜吧。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r1",
]));
  set("objects", ([ /* sizeof() == 1 */
  BAD_NPC"lee" : 1,
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object who, string dir)
{
  if( present("lee da tswei", this_object()) ) {
  if( dir=="south" && who->query_skill("badforce",1)>30 && who->query("bellicosity")>200 && who->query("quests/evilup")!=1 && who->query_temp("evilup")!=1) {
  switch(random(3)) {
  case 0:
    who->set_temp("evilup",1);
   who->set_temp("yang",1);
   tell_object(who,"李大嘴咧嘴說道 :唉呦 ,怎啦 ?愁眉苦臉的 ,啥 ?不知道怎麼更好\n好利用惡化魔功\ ?嘿 ,這個簡單....不過你倒要幫我做件事 ,只要\n你把楊心婷那小妮子拿來給我嚐嚐 ,包準教到你會為止 !....記得\n ,要新鮮的喔。\n");
    break;
  case 1:
    who->set_temp("evilup",1);
   who->set_temp("kou",1);
   tell_object(who,"李大嘴咧嘴說道 :唉呦 ,怎啦 ?愁眉苦臉的 ,啥 ?不知道怎麼更好\n好利用惡化魔功\ ?嘿 ,這個簡單....不過你倒要幫我做件事 ,只要\n你把郭嘯風那條漢子拿來讓我嚐嚐 ,包準教到你會為止 !....記得\n ,要新鮮的喔。\n");
    break;
  case 2:
    who->set_temp("evilup",1);
   who->set_temp("chen",1);
   tell_object(who,"李大嘴咧嘴說道 :唉呦 ,怎啦 ?愁眉苦臉的 ,啥 ?不知道怎麼更好\n好利用惡化魔功\ ?嘿 ,這個簡單....不過你倒要幫我做件事 ,只要\n你把陳玄龍那結實的身子拿來讓我品味品味 ,包準教到你會為止 !\n....記得 ,要新鮮的喔。\n");
    break;
    default:
    return notify_fail("嘿 ,加油啊 !\n");
   }
  }
}
    return ::valid_leave(who, dir);
}
