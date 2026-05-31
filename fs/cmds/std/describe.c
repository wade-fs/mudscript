// describe.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int main(object me, string arg)
{
        if(arg == "none")
        {
                me->delete("describe");
                write("Describe 清除。\n");
        } else {
        //me->edit( (: this_object(), ({ "do_describe", me}) :) );
        me->edit( (: call_other, __FILE__, "do_describe", me :) );
        }
        return 1;
}

void do_describe(object me, string text)
{
        me->set("describe", text);
        write("Describe 設定完成。\n");
}

int help(object me)
{
write(@HELP
指令格式 : describe || describe none
指令說明 :
           describe 可以替自己美容，會改變玩家看你的敘述。
           describe none 可以清除設定。
相關指令 :
           look
HELP
    );
    return 1;
}

