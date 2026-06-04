// suicide.c
// 不讓巫師可以自殺了, wade 3/17/1996
// 為了不讓自殺使幫派系統亂掉.幫派的人不能自殺。
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        if( !arg || (arg!="-f" && arg!="-n"))
          return notify_fail("自殺有兩種﹐您是要永遠死掉還是重新投胎﹖\n");
        if( pointerp(me->query_team()) )
          return notify_fail("請先脫離隊伍再自殺\n");
        // 不讓巫師可以自殺了, wade 3/17/1996
        // 但讓 wiz 能藉重新投胎以更新身區。 lys 5/2/1996
        if( me->query("clan/name"))
                return notify_fail("加入幫派的人請先脫幫後再自殺!!!\n");
        if (wizardp(me) && arg!="-n") {
          write ("巫師請您以 post 或寄信給 manager 的方式自殺.\n\n");
          return 1;
        }
 
        if (arg == "-n") {
                write("你真的要重新投胎嗎? 放棄一切成為新生兒嗎? (y/n)");
                input_to("confirm_reborn",0, me);
                return 1;
                }
        else if(arg == "-f") {
                write(
                "如果您選擇永遠死掉的自殺方式﹐這個人物的資料就永遠刪除了﹐請務必\n"
                "考慮清楚﹐確定的話請輸入您的密碼﹕");
                input_to("check_password", 1, me, 1);
                return 1;
        }
}
 
void confirm_reborn(string yn, object me)
{
 
        if( yn=="") {
                write("你真的要重新投胎嗎? 放棄一切成為新生兒嗎? (y/n)");
                input_to("confirm_reborn",0, me);
                return;
        }
        if( yn[0] != 'Y' && yn[0] != 'y' ) {
                write("你能想開真好, 繼續努力吧, 相信明天會更好!\n");
                return;
        }
 
        write(
               "如果你選擇重新投胎，將會清除你所有的資料，並重設屬性。\n"
               "考慮清楚﹐確定的話請輸入您的密碼﹕");
        input_to("check_password", 1, me, 0);
        return;
}
int reset_body(object me)
{
        object new_body, old_link = me->query_temp("link_ob");
        new_body = LOGIN_D->make_body(old_link);
        new_body->set("gender",me->query("gender"));
        exec(old_link,me);
        destruct(me);
        new_body->set("str",0);
        new_body->set("cps",0);
        new_body->set("int",0);
        new_body->set("cor",0);
        new_body->set("con",0);
        new_body->set("spi",0);
        new_body->set("per",0);
        new_body->set("kar",0);
        write("重新調整你的天覆賦, 請好好選擇設定。\n");
        write ("請問您希望的膂力" +
               "是多少? 合法的值是 10-30, 目前剩下 160 : ");
        input_to("get_points",0, old_link,new_body);
 
}
void get_points( string points, object ob, object user)
{
        LOGIN_D->get_points(points, ob, user, 160, "str", 1);
        shout ("西方紅光乍現，"+user->name()+"重新轉生於世。\n");
        return;
}
void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass,id;
        int stage;
 
        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("密碼錯誤﹗\n");
                return;
        }
 
        if (forever) {
                tell_object( me,
                        HIR + "\n\n你決定要自殺了﹐永別了!!!!\n\n\n" + NOR);
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;
        seteuid(getuid());
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
 
        // 處理信件
        id =  me->query("id");
        rm( DATA_DIR + "mail/" + id[0..0] + "/" + id+".o");
 
        write("好吧﹐永別了:)\n");
        shout (me->name() + "自殺了﹐以後你再也看不到這個人了。\n");
        destruct(me);
        return 0;
        }
        else
                reset_body(me);
}

int slow_suicide(object me)
{
        string  id;
        object link_ob;
        int stage;
 
        stage = me->query_temp("suicide_countdown");
        me->add_temp("suicide_countdown", -1);
        if( stage > 0 ) {
                tell_object(me, HIR + "你還有 " + (stage-1) + " 秒的時間可以後悔。\n" + NOR);
                return 1;
        }
 
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;
 
        seteuid(getuid());
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
 
        // 處理信件
        id =  me->query("id");
        rm( DATA_DIR + "mail/" + id[0..0] + "/" + id+".o");
 
        write("好吧﹐永別了:)\n");
        shout (me->name() + "自殺了﹐以後你再也看不到這個人了。\n");
        destruct(me);
        return 0;
}
 
int help (object me)
{
        write(@HELP
指令格式 : suicide [-f || -n]
指令說明 : 
             如果因為某種原因你不想活了, 你可以選擇自殺.
             自殺分兩種:
 
suicide -n : 重新投胎 (清除一切資料，重新設定屬性。)
suicide -f : 永遠的除去玩家資料, 系統會要求你
             輸入密碼以確認身份.
 
請慎重選擇 :)
HELP
);
        return 1;
}
