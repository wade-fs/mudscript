// Room: /u/g/guetenr/beggar/room/beg1/class35.c
inherit ROOM;

void create ()
{
  set ("short", "土地廟");
  set ("long", @LONG
在水田裏有一塊地方地勢略高一些，理應雜草蔓生的地上卻整理成草坪
，倒像是一處庭院；東邊一棵老樹上幾隻鳥兒正啁啾鳴唱著，樹下卻是一間
小小的土地廟，供奉著慈靄的土地公，看那神像已被香煙燻得面目有些黧黑
，想來是感恩的莊稼人終年香火不絕所致。廟中躺著一個枯瘦的老人，看他
的樣子似乎很多天沒吃飯了，賞個銅錢給他吧。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room33",
]));

  setup();
}
