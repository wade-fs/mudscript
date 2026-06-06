inherit ROOM;

void create()
{
  set ("short", "民房");
  set ("long", @LONG
殘破的木製房屋，由幾片木板隨意拼湊而成。門口似乎連門都沒
有，地上隨意挖了一個洞當作炕，上面還擺了一個破鍋，鍋內除了清
水卻什麼都沒有。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"j30.c",
  ]));
  setup();
}
