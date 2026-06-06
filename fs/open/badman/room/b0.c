// Room: /open/badman/room/e1.c

inherit ROOM;

void create ()
{
  set ("short", "惡人谷入口");
  set ("long", @LONG
這裡就是傳說中惡人谷的入口，據說在谷中之人沒有一個不是
十惡不赦，滿手血腥，沒有一個不被江湖中人恨之入骨。但也正因
為聚集在此的都是江湖中的極惡之徒，別人縱然恨不得吃他們的肉
，卻也沒有人敢走近惡人谷一步。
    在淒迷的雲霧中，一盞青燈製成的孔明燈正巧妙的嵌在山石間
的避風處，看來有如鬼火一般。在燈火的照耀下，山石上似乎刻著
兩行字(words)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "words" : "
	入谷如登天，
	來人走這邊。
",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/yen" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "leave" : "/open/badman/room/t6",
  "west" : "/open/badman/room/b1",
]));

  setup();
}

int valid_leave(object who, string dir)
{
  if( present("sma yen", this_object()) ) {
  if( dir=="west" && !present("badman license", who) ) {
    switch(random(4)) {
      case 0:
        return notify_fail("司馬煙冷冷的對你笑道: 朋友，惡人谷不是你想來就來的地方，請留步。\n");
        break;
      case 1:
        return notify_fail("司馬煙拿起手中的劍擋在你面前說道: 想入谷？先問問看我手中的穿腸劍答不答應！\n");
        break;
      default:
        return notify_fail("司馬煙對你搖了搖頭道: 谷主有令，無惡人證者不得擅入惡人谷，違者格殺勿論！\n");
    }
  }

  if( dir=="west" && present("badman license", who) )
    message_vision("司馬煙看了看$N的惡人證說道: "+who->query("name")+"，你可以過去了。\n\n", who);
  }

  return ::valid_leave(who, dir);
}
