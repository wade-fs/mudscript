// csub_room.c
//
//                                              Created by Arthur

#define SAVE_ROOM       "別忘了 csaveroom, 儲存此次的修改。\n"

inherit F_CLEAN_UP;

int main(object me, string str)
{
        if( me->query("clan/rank") > 3)
                return notify_fail("你無權使用此指令。\n");
        if( !CLAN_D->is_clan_room(me) )
                return notify_fail("這個房間並不是你們幫派所屬的。\n");
        if( !environment(me)->query("item_desc/"+str))
        return notify_fail("沒有這個景觀。\n");
         write("你刪除了這房間所["+str+"]的景觀!!\n");
       environment(me)->delete("item_desc/"+str);
        write(SAVE_ROOM);
        return 1;
}
int help( object me )
{
        write("
    csub_item     ：取消景觀設定。
    csub_item <景觀>

                                                         by ACKY 2000/02/23
");
        return 1;
}

