inherit ROOM;
 void create()
{
  set ("short","廟庭中的大洞");
  set ("long",@LONG
這是一個坍塌的大洞，身後便是剛闖進來的地方。但用力推開的
石堆又因為你的使力過猛，又再度坍方。你仔細地看了一下周圍，發
現身處的大洞顯然地是由一股相當強大的外力所造成。在前方不遠處
有股奇妙的藍光正在閃爍著。
LONG);

  set("outdoors", "/open/badman");

  set("exits", ([ /* sixeof() == 1 */
  "west" : __DIR__"bump01.c",
]));

  setup();
}
