#include <room.h>
inherit ROOM;

void create()
{
        set("short", "天險");
        set("long", @LONG
從奔雲階拾級而上，你來到了一座巨大的城池門口，這整座城池往左
右延伸了大約兩公里，而眼前的城門也讓你目瞪口呆，這扇城門寬度約十
五公尺，高度約二十公尺，門的兩旁各有一座奇怪的石像 (statue) ，除
了一路走來的階梯以及眼前的城池，四周圍都是渺茫一片，一個失足便可
能摔到百尺之下的平原。
LONG
        );
        set("exits", ([
           "north": __DIR__"n5",
]));
        set("outdoors",1);
        set("objects", ([
]));
        set("item_desc", ([
        "statue":"奇怪的彫刻，看起來不像是人間的生物，右邊石像的胸口有個菱形的凹陷(section)。\n",
        "section":"一個呈菱形的凹陷塊﹐看起來可以嵌入些甚麼。\n",
        ]) );

        setup();
}

void check_trigger()
{
        object room;
        if( (int)query("door_open")==1
        &&      !query("exits/south") ) {
                message("vision", "\n隨著轟轟的聲響﹐天界之城的大門打開來了。\n",this_object());
                set("exits/south", __DIR__"land_square");
                if( room = find_object(__DIR__"land_square") ) {
                        room->set("exits/north",__DIR__"land_gate");
                message("vision", "\n隨著轟轟的聲響﹐天界之城的大門打開來了。\n",room);
                }
                delete("door_open");
                call_out("close_passage", 10);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/south") ) return;
        message("vision", "\n隨著轟轟的聲響﹐天界之城的大門關起來了。\n",this_object() ); 
        if( room = find_object(__DIR__"land_square") ) {
                room->delete("exits/north",__DIR__"land_gate");
        message("vision", "\n隨著轟轟的聲響﹐天界之城的大門關起來了。\n",room);
        }
        delete("exits/south");
}

void reset()
{
        ::reset();
        delete("door_open");
}

void init()
{
        add_action("do_insert", "insert");
}

int do_insert(string arg)
{
        string dir;
        object medal;
        medal = (present("dragon-medal",this_player()));

   if ( arg=="medal" || arg=="dragon-medal" ){
        if(present("dragon-medal",this_player())){
        message_vision("喀喳一聲﹐$N將手上的龍涎嵌入石像。\n",this_player());
        add("door_open",1);
        check_trigger();
        return 1;
        }
        write("你想將什麼崁入石像﹖\n",this_player());
        return 1;
        }
        return 0;
}

