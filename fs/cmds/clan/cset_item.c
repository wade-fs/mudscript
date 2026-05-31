// cset_item.c
//
//                                              Created by Chan

#define SAVE_ROOM       "別忘了 csaveroom, 儲存此次的修改。\n"
void done_setitem(string str, string text);

int main(object me, string arg)
{
        if( !CLAN_D->is_clan_room(me) )
                return notify_fail("這個房間並不是你們幫派所屬的。\n");
        if( me->query("clan/rank") > 3)
                return notify_fail("你無權使用此指令。\n");
        if( !arg )
                return notify_fail("指令格式﹕cset_item <景觀的英文>\n");
        me->edit( (: done_setitem,arg :) );
        return 1;
}

void done_setitem(string str,string text)
{
        mapping objs;
objs=environment(this_player())->query("item_desc");
if(!objs)  objs = ([ str : text ]);
else  objs += ([ str : text ]);
        environment(this_player())->set("item_desc", objs);
        write(SAVE_ROOM);
        return;
}

int help( object me )
{
        write(@HELP

格式說明:csetitem <景觀英文>

此指令用來設定房間內景觀的敘述!!
例如:
     csetitem board
     此時就會要你輸入baord 的長敘述!!!!
     完成之後,幫眾可以打look board 便可以看到board中的長敘述!!!!

HELP    );
        return 1;
}



