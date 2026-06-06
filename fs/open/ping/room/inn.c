// Room: /open/ping/room/inn.c

inherit ROOM;

void create ()
{
  set ("short", "木板吊橋");
  set ("long", @LONG
這裡可是正晴武館的私人吊橋,正晴武館就在吊橋的那一邊,
你如果沒事的話,還是不要去惹這平南城的大富豪.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road9",
  "east" : "/open/wu/room/luroom1",
]));
  set("outdoors", "/open/wu");

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
