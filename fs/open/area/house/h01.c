 inherit ROOM;

void create()
{
        set("short","民舍");
        set("long",@LONG
木造的房屋與儉樸的裝飾，是個十足的鄉村人家房內的屋飾，一
踏入門就可以看到一張方正的四腳木桌，木桌四周各擺設著四張與木
桌桌角切齊的板凳，再往內只有一張木床，木床上有個縫縫補補過的
棉襖與米糠做成的枕頭，房屋兩側橫擺著幾個農家釘杷與砍刀，除此
之外以無其他東西。
LONG);
        set("exits",([
"south":"/open/start/room/s1",
]));
        set("objects",([
__DIR__"npc/man01":1,
__DIR__"npc/children01":1,
]));
        set_temp("area/house",1);
        setup();
}
