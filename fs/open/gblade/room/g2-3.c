inherit ROOM;

void create ()
{
  set ("short", "瀉玉亭");
	set( "build", 19 );
  set ("long", @LONG

進入此處，只見佳木成蔭，奇花爛漫，一灣清流，從奇花深處瀉於石隙之
下。清溪瀉玉，石磴穿雲；白石為欄，環抱池沼。溪上有橋，橋上有亭，
亭上有一赤金九龍青地大匾（sign）。

LONG);
 set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "

只見上面寫著

                  亭   玉   瀉  

            隔                     繞
            岸                     隄
            花                     柳
            分                     借
            一                     三
       王   脈                     篙
       元   泉                     翠
       霸
       題
 
沒想到王元霸除了在武功\尚有驚人的造詣之外，文學上的成就
也是不凡。\n",

]));

   set("light_up", 1);
set("outdoors", "/open/gblade" );
   set("exits", ([ /* sizeof() == 3 */
"east" : __DIR__"g2-2.c",
"north" : __DIR__"g2-5.c",
"west" : __DIR__"g2-4.c",
]));

  setup();
}

