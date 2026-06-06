inherit ROOM;

void create ()
{
  set ("short", "玄機房");
  set ("long", @LONG
這裡就是傳說中的六脈劍聖---段譽及其妻王語嫣所居住的地方,玄機房了
,裡面的擺設十分的豪華別致,有如皇宮一般,但是你找來找去,卻都找不到段譽
的身影,看來段譽不在這裡。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aa22",
]));

  setup();
  replace_program(ROOM);
}
