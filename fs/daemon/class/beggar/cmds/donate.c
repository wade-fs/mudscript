// donate.c by Anmy

#include <ansi.h>

inherit F_GUILDCMDS;

void pre_donate();
void do_donate(object ,object);

int main(object me, string arg)
{
        object env;
        object *inv;
        int i;
        env = environment(me);

        if( arg=="cancel" ) {
                if( !me->query_temp("募捐中") )
                        return notify_fail("怎啦,你還沒準備好募捐吧..\n");
                tell_object(me, HIW + "你開始收起破碗公,離開這裡。\n" + NOR);
                me->delete("greeting_msg");
                me->set("id", me->query("old_id"));
                me->set("name", me->query("old_name"));
                me->set("nickname", me->query("old_nick"));
                me->set("title", me->query("old_title"));
                me->delete("old_id");
                me->delete("old_name");
                me->delete("old_nick");
                me->delete("old_title");
                me->delete_temp("募捐中");
                me->delete_temp("不准走");
                return 1;
        }
        if( me->query_temp("募捐中") )
                return notify_fail("你已經把破碗公準備好收錢了...\n");
        if( me->is_fighting() )
                return notify_fail("把敵人打死了錢自然是你的，搶什麼搶。\n");
        inv = all_inventory(env);
/*
        for( i=0; i<sizeof(inv); i++ ) {
                if( userp(inv[i]) && inv[i]!=me )
                        return notify_fail("這裡還有別人在，現在蒙面會被發現吧。\n");
        }
*/
        tell_object(me,"你把破碗公放到地上,等待人來施捨..\n");
        if( !me->query("old_id") ) {
                me->set("old_id", me->query("id"));
                me->set("old_name", me->query("name"));
                me->set("old_nick", me->query("nickname"));
                me->set("old_title", me->query("title"));
                me->set("id", "buddha");
                me->set("name", "佛陀");
                me->set("title", HIY + "傳道．授業．解惑也" + NOR);
                me->delete("nickname");
        }
        me->set_temp("募捐中", 1);
        me->set_temp("不准走", 1);
        me->set("greeting_msg", ({
        (:call_other,file_name(this_object()),"pre_donate":),
        }) );
        return 1;
}

void pre_donate()
{
        int i;
        object *inv, bandit;
        object ob = this_player();

//        if( wizardp(ob) ) return;

        inv = all_inventory(environment(ob));
        for( i=0; i<sizeof(inv); i++ ) {
                if( inv[i]->query_temp("募捐中") )
                        bandit = inv[i];
        }

        if( ob->query_temp("已捐錢") )
return;
        ob->set_temp("不准走", 1);
        call_out("do_donate", 1, bandit, ob);
}

void do_donate(object bandit, object ob)
{
        int face, money, kee;

        tell_object(bandit,HIW + "\n 你正盤坐在地上, 微笑的對著"+ob->name()+"說：\n\n『阿彌陀佛, 我佛慈悲, 施主是否能施捨點錢, 以便重建天龍寺』\n\n" + NOR);

        face =( bandit->query_skill("change",1)+bandit->query_kar() < random(ob->query("combat_exp")/10000)+ob->query_int() );
        if( face )  tell_object(bandit,HIW + "啊, 對方已看穿以是假冒的。\n" + NOR);


        tell_object(ob,HIC + "\n你往下一看，"+(face?bandit->query("old_name"):"一個和尚")+"正微笑的看著你說：\n\n『阿彌陀佛, 我佛慈悲, 施主是否能施捨點錢, 以便重建天龍寺』\n\n" + NOR);

        money = ( ob->query("combat_exp")/5000 + 1 ) * 100;

        if( bandit->query_kar()*bandit->query("combat_exp")/10 > ob->query_cor()*ob->query("combat_exp")/20 ) {
                tell_object(bandit,"於是你對"+ob->name()+"敘說著種種道理，"+ob->name()+"似乎有開悟的感受，所以"+ob->name()+"毫不客氣的捐了點錢給你。\n");
tell_object(ob,"於是和尚對你敘說著種種道理，你似乎有開悟的感受，所以你毫不客氣的捐了點錢給和尚\n");
                if( ob->can_afford(money) ) {
                        ob->pay_money(money);
                        bandit->pay_player(money);
                        tell_object(ob,HIC + "你捐給"+(face?bandit->query("old_name"):"和尚")+"一些心意。\n" + NOR);
                        tell_object(bandit,HIC + ""+ob->name()+"捐給一點心意。\n" + NOR);
                        tell_object(ob,HIW + ""+(face?bandit->query("old_name"):"和尚")+"微笑的說道：施主此行大恩大德, 改日另行感謝\n" + NOR);
                        tell_object(bandit,HIW + "你微笑的說道：施主此行大恩大德,改日另行感謝\n" + NOR);
                } else {
                        tell_object(ob,(face?bandit->query("old_name"):"和尚")+"看你身上好似沒錢，微笑的說: 讓和尚我為您強健身筋吧。\n");
                        tell_object(bandit,"你看著"+ob->name()+"身上好似沒錢，微笑的說: 和尚我來教你點強身之道吧。\n");
                        kee = ob->query("eff_kee")*3/4;
                        ob->set("eff_kee", kee);

tell_object(ob,HIC + ""+(face?bandit->query("old_name"):"和尚")+"教了你一些基本基礎的功\夫, 你發覺快累垮了。\n" + NOR);
                        tell_object(bandit,HIC + "你教了"+ob->name()+"一點基本的功\夫。\n" + NOR);
                        tell_object(ob,HIY + ""+(face?bandit->query("old_name"):"和尚")+"對著你微笑：行走江湖要小心點, 以免受傷\n" + NOR);
tell_object(bandit,HIY + "你對著"+ob->name()+"微笑: 行走江湖要小心點\n" + NOR);
                }
        } else {
                if( bandit->can_afford(money) ) {
tell_object(ob,"和尚說著種種道理,你絲毫沒有聽進去,只看著和尚的碗公有錢,於是你就心存邪念,搶了可憐和尚的錢。\n");
tell_object(bandit,"你說著種種道理,"+ob->name()+"絲毫沒有聽進去,只看著你的碗公有錢,於是"+ob->name()+"就心存邪念,搶了你的錢。\n");
                        bandit->pay_money(money);
                        ob->pay_player(money);
tell_object(ob,HIY + ""+bandit->query("old_name")+"施捨了點錢給你。\n" + NOR);

tell_object(bandit,HIY + "你施捨了"+ob->name()+"一些錢。\n" + NOR);
                } else {
tell_object(ob,"和尚說著種種道理,你絲毫沒有聽進去,只看著和尚的碗公有錢,於是你就心存邪念,搶了可憐和尚的錢。\n");
tell_object(bandit,"你說著種種道理,"+ob->name()+"絲毫沒有聽進去,只看著你的碗公有錢,於是"+ob->name()+"就心存邪念,搶了你的錢。\n");
                        kee = bandit->query("eff_kee")*3/4;
                        bandit->set("eff_kee", kee);
                        tell_object(ob,HIC + "你將"+bandit->query("old_name")+"的錢狠狠的全拿光。\n" + NOR);
                        tell_object(bandit,HIC + ""+ob->name()+"將你的錢拿光了。\n" + NOR);
                }
                tell_object(ob,HIC + "你仰天長笑說："+bandit->query("old_name")+"算你倒霉,本大人信耶穌不信佛\n" + NOR);
                tell_object(bandit,HIC + ""+ob->name()+"仰天長笑著說："+bandit->query("old_name")+"算你倒霉, 本大人信耶穌不信佛的啦, 哇哈哈哈哈哈哈哈哈..\n" + NOR);
        }

        ob->delete_temp("不准走");
        ob->set_temp("被搶過", 1);
}

int help(object me)
{
        write(@HELP

指令格式： cmd donate [cancel]

說明：此指令能讓你就地對路人募錢
      自己不能移動。
      加上 cancel 參數會停止募捐。

HELP);
        return 1;
}
