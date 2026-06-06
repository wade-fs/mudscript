#include <room.h>

 inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG
          
  這兒是仙劍派為了灑掃方便而貌漱p茅屋，你從門外聞到一陣陣的惡臭，
不時還傳來驚天動地的呼聲，從窗外往裡邊一看，裡頭住的竟然是一位一衫
的醉翁。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"rroad2",
  "enter" : __DIR__"house",
]));
  set("outdoors", "/open/gsword/room");

  setup();
}
