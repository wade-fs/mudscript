// Room: /open/capital/room/h07.c

inherit ROOM;

void create ()
{
  set ("short", "扁鵲胡同");
  set ("long", @LONG
這裡的街道依然乾淨, 唯一不同的是路旁群聚著一群人, 原來是有
人在一旁說書, 聽他口中滔滔不絕, 似乎是在回顧以前的歷史, 一代興
起, 一朝衰弱, 當然圍觀的民眾是聽的興趣盎然。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/h06",
  "east" : "/open/capital/room/h08",
]));

  set("outdoors", "/open/capital");


  setup();
}
