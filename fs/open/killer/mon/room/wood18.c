//written by acelan...../u/a/acelan/room/wood18.c

inherit ROOM;

void create()
{
        set("short", "神木之底");
        set("long", @LONG
這裡是中央神木的底部, 神木的中心已經被人挖空, 可以直接通
往地面, 垂下來的木梯受潮很嚴重, 看起來似乎已經不堪使用了, 四
周佈滿了青苔, 顯然已經很久沒有人到過這裡來了。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "up" : "/open/killer/mon/room/wood19.c",
       "west" : "/open/killer/mon/room/wood17.c",
   ]));
        set("no_clean_up", 0);

        setup();
        }
