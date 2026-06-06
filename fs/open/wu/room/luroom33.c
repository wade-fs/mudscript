// Room: /open/wu/room/luroom33.c
// 瀧山內院書房
inherit ROOM;
void create()
{
        set("short", "書房");
        set("long", @LONG
這裏是任正晴的書房,藏書雖然不多,但也甚為可觀,書房的桌上
放著一本書,仔細一看書名好像是基本拳法,由於任正晴一年也難
得進書房幾次,所以書都看來很新!!牆上有一幅對聯(couplet),
是任正晴親手題的．
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"luroom32",
        ]));
        set("item_desc", ([
       "couplet" : "
  
            忠                                  浩

            肝                                  氣

            義                                  長

            膽                                  存

            為                                  保

            國                                  家  任
                                                    正
            家                                  鄉  晴
          "]));
        set("light_up", 1);
        setup();
}
