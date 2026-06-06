// Room: /u/d/devils/school10.c

inherit ROOM;

void create()
{
	set("short", "藏經閣");
	set("long", @LONG
這是任正晴的書房,藏書號稱三千卷,武館中諂媚弟子把它取名為藏經閣
來拍館主馬屁,事實上,好像也只是藏書間,因為任正晴一年也難得進書房幾次
,更別提讀書了!牆上有一幅對聯(couplet),是任正晴親手題的．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"school8",
]));

        set("item_desc", ([
"couplet" : @LONG
                  
                        誰      來      挑      戰
  
                  拳                                  腳

                  打                                  踢

                  黃                                  李

                  飛                                  小

                  鴻                                  龍

LONG
            ]));
        set("light_up", 1);
        setup();
}
