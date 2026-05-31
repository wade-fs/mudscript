// perform.c
inherit F_CLEAN_UP;
inherit F_FUNCTION;
int main(object me, string arg)
{
        object weapon;
        string martial, skill;
        int result;
        seteuid(getuid());
        if( !arg ) 
                return notify_fail("你要用外功\做什麼﹖\n");
        if( me->query("force") < 0 )
     {
     me->set("force",0);
   tell_object(me,"沒內力了用什呀?\n"); 
   return 1;
     }
        if(me->query_temp("is_busy"))
                return notify_fail("你的內息翻滾不定,暫時無法使用外功\!!!\n");
        if(me->query_temp("is_busy")||me->is_busy() || me->query_condition("force") > 0 )
        return notify_fail("你一運氣用力，發覺丹田中毫無內息。\n");

//sun_fire_sword 特殊功能

        if( me->query_condition("no_power") )
                return notify_fail("炫目的劍光還殘留在你眼底，使你無法全力運氣。\n");

        if( me->query_condition("no_power_f") )
                return notify_fail("你被身旁的龍捲氣勁所阻，因此你無法以自由使用絕招\n");

        if( me->query_temp("arrayp") )
                return notify_fail("陣法剛開始運轉，你沒辦法分心使用絕招\n");
                
    /*    if(me->query_temp("crazy"))
                return notify_fail("你正陷入狂暴狀態，無法自由操縱內息。\n");         */
        
          if( !environment(me) || environment(me)->query("no_fight") )
             return notify_fail("這裡不准戰鬥。\n");

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else
                        martial = "unarmed";
        }
//add by bss 因為有perform不能用的現像,故檢查一下
/*
        if(!(TEMP_D->update_perform(me,martial,arg)))
                return 0;
*/

        if( stringp(skill = me->query_skill_mapped(martial)) )
        {
                if( SKILL_D(skill)->perform_action(me, arg) ) 
                {

			
                      	 	 me->set_temp("is_busy",1);
                        call_out("del_busy",4,me);
                 		return 1;
	
                }
        }
        if(!find_object(SKILL_D(martial)))
          if(!load_object(SKILL_D(martial)))
            return 0;
        if( SKILL_D(martial)->perform_action(me, arg) ) {

                me->set_temp("is_busy",1);
             call_out("del_busy",4,me);
                return 1;
        }
        return 0;
}

void del_busy(object me) {

        if( me )        // 使用 call_out 一定要檢查 player 是否在嗎
                me->delete_temp("is_busy");
        return;
}

int help(object me)
{
        write(@HELP
指令格式 : perfrom [<武功種類>.]<招式名稱> [<施用對象>]
指令說明 :
           如果你所學的外功(拳腳、劍法、刀法....)有一些特殊的攻擊
     方式或招式﹐可以用這個指令來使用﹐你必須先用 enable 指令指定
     你使用的武功﹐不指定武功種類時﹐空手的外功是指你的拳腳功夫﹐
     使用武器時則是兵刃的武功。
           若是你的外功中有種類不同﹐但是招式名稱相同的﹐或者不屬
     於拳腳跟武器技能的武功(如輕功)﹐可以用 <武功>.<招式>  的方式
     指定﹐如﹕
        perform sword.powerfocus 
        perform move.reflexion
           換句話說﹐只要是 enable 中的武功有特殊招式的﹐都可以用
     這個指令使用。

□ 附錄 基本技能的外功
        以下是基本技能中含有外功功能的部份

基本技能   外功名稱   用法                                附註
基本劍法   劍氣       perform sword.swordkee [<target>]   劍士、刀客、武者
讀書識字   教誨訓示   perform literate.preach [<target>]  書生
HELP
        );
        return 1;
}
