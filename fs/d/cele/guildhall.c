inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 水煙閣前");
  set ("long", @LONG
    這裡是水煙閣的正廳﹐簡單的陳設中透出一股尊貴不凡的氣派﹐一
張黝黑的太師椅端坐在大廳中央﹐這裡同時也是「武者」們議事的所在
﹐每年的正月十七都要在水煙閣外的「虹台」推選武林盟主﹐然後在這
裡舉行登位大典。

LONG);

  set("outdoors", "cele");
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south": "/d/cele/enter",
]));

        set("objects", ([
                "/d/cele/npc/champion":1,
                "/d/cele/npc/master":1
        ]) );


  setup();
}
