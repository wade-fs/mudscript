// learn.c 修正 by babe

#include <ansi.h>
#include <basic_skill.h>
#include <skill.h>

string *reject_msg = ({
	"說道﹕您太客氣了﹐這怎麼敢當﹖\n",
	"像是受寵若驚一樣﹐說道﹕請教﹖這怎麼敢當﹖\n",
	"笑著說道﹕您見笑了﹐我這點雕蟲小技怎夠資格「指點」您什麼﹖\n",
});

varargs int main( object me, string arg, int repeat )
{
	string skill, teacher, master,my_class;
	string record;
	mapping level;
	object ob;
	int master_skill, my_skill, gin_cost;
    int i,r = 0;
  int max_skill;

	seteuid(getuid());

        if( !arg || sscanf( lower_case(arg), "%s from %s", skill, teacher )!=2 )
                return notify_fail( "指令格式﹕learn <技能> from <某人>\n" );

    if( sscanf( skill, "%d %s", repeat, skill) != 2 )
		arg = skill;                                                         
	if( skill=="sun_fire_sword" ) {
		return notify_fail( "此技能只能用讀的！\n" );
	}
	if( skill=="paull-steps" && me->query("class") != "dancer" && (int)(me->query_skill("paull-steps", 1))==100)
	  { return notify_fail( "你不是舞者不能再往上學了！\n" );
	}
    if( skill=="nine-steps" && me->query("class") != "poisoner" && (int)(me->query_skill("nine-steps", 1))==100)   
	  { return notify_fail( "你不是魔教徒不能再往上學了！\n" );
	}
	if( me->is_fighting() )
		return notify_fail( "臨陣磨槍? 來不及啦。\n" );
	if( !( ob = present( teacher, environment(me) ) ) || !ob->is_character() )
		return notify_fail( "你要向誰求教?\n" );
     if( ob->query("make_clan") || ob->query("clan_make"))
		return notify_fail( "請勿向 clan_npc 求教, 這是bug!\n" );
	if( ob->query("no_learn")==1 )
		return notify_fail( "請勿向 clan_npc 求教, 這是bug!\n" );
       if( ob->query_temp("搶劫中") || ob->query_temp("不准走") || ob->query_temp("募捐中"))
             return notify_fail( "蒙面強盜不方便傳授技能!!\n" );
	if( ob->query("master") )
		return notify_fail( ob->query("name")+"無法教你這個技能。\n" );
	if( me->query("horse")==1 || ob->query("horse")==1 )
		return notify_fail( "馬不能學習。\n" );
	if( !living(ob) )
		return notify_fail( "嗯.. 你得先把" + ob->name() + "弄醒再說。\n" );
	if( wizardp(ob) )
		return notify_fail( "不能跟巫師學技能。\n" );
	if( !mapp(basic_skill[skill]) ) {
		if( !me->is_apprentice_of(ob) ) {
			if( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ||
			    (int)ob->query("family/privs") != -1)
				if( me->query("class") != ob->query("class") ||
				    !me->query("class") || !ob->query("class") ) {
					notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
					if( !(ob->recognize_apprentice(me)) )
						return 0;
				}
		}
		else
			if( me->query("class") != ob->query("class") || !me->query("class") || !ob->query("class") )
				return notify_fail(ob->query("name")+"說：\n你和我是不同的職業，恕我不能教你。\n");
	}
	if( skill == basic_skill[skill] ) {
		if( !ob->query("guild_master") && !me->is_apprentice_of(ob) )
			return notify_fail( "基本技能只能跟工會老大學,\n或是跟你的師父學。\n" );
	}
	else
		if( ob->query("family/family_name") != me->query("family/family_name") )
			return notify_fail( "特殊技能只能向同門派的人學。\n" );

	if( !me->is_apprentice_of(ob) && skill=="spiritism" )
		return notify_fail( "御魂術只能向師父求教, 或是自行修練。\n" );

 	if( !ob->query("guild_master") && !me->is_apprentice_of(ob) &&
	    !( ob->query("env/傳授/all/all") || ob->query("env/傳授/all/"+skill) ||
	    ob->query("env/傳授/"+me->query("id")+"/all") || 
	    ob->query("env/傳授/"+me->query("id")+"/"+skill) ) )
		return notify_fail( "對方看起來並不想教你這個技能！\n" );
        if( me->query("family/master_is_ppl") && me->is_apprentice_of(ob) && !userp(ob))
                return notify_fail("他不是你師父，要學技能請找你真正的師父。\n");
	if( !master_skill = ob->query_skill( skill, 1 ) )
		return notify_fail( "這項技能你恐怕必須找別人學了。\n" );
	if( !SKILL_D(skill)->valid_learn(me) )
return SKILL_D(skill)->valid_learn(me);
// return notify_fail( "依你目前的能力﹐沒有辦法學習這種技能。\n");
	gin_cost = 150 / (int)ob->query_int() + 150 / (int)me->query_int();

	if( userp(ob) )
		tell_object( ob, sprintf( "%s向你請教有關「%s」的問題。\n",
			me->name(), to_chinese(skill)) );
	printf( "你向%s請教有關「%s」的疑問。\n", ob->name(), to_chinese(skill) );

	if( repeat==0 )
		repeat = 1;
    if(repeat > 500) repeat=500;
  max_skill = (int)ob->query("env/傳授/"+skill);
	for( i=0; i<repeat; i++ ) {
		my_skill = me->query_skill( skill, 1 );
    if(max_skill != 0 && max_skill <= my_skill)
      return notify_fail( "師父覺得你的資質只能學到這個程度。\n");

		if( my_skill >= master_skill )
			return notify_fail( "這項技能你的程度已經不輸此人了。\n" );
		if( !my_skill ) {
			gin_cost *= 2;
			me->set_skill( skill, 0 );
		}
		if( (int)me->query("learned_points") >= (int)me->query("potential") )
			return notify_fail( "你的潛能已經發揮到極限﹐沒有辦法再成長。\n" );
		if( (int)me->query("gin") > gin_cost ) {
			if( (string)SKILL_D(skill)->type()=="martial" && ((my_skill*my_skill*my_skill/300 )*my_skill>me->query("combat_exp") ||  my_skill >= 350) )
				return notify_fail( "由於缺乏實戰經驗﹐你無法領會"+ob->name()+"的教導。\n" );
			else {
				r = 1;
				me->add( "learned_points", 1 );
				me->improve_skill( skill, random(me->query_int() + ob->query_skill(skill,1)/5) );
				/*if( random(1000) < 1 ) {
					ob->improve_skill( skill, random(ob->query_int()) );
					tell_object( ob, sprintf( HIC + "在你教導%s有關「%s」的同時, 突然悟出「%s」更深一層的奧秘。\n" + NOR,
							me->name(), to_chinese(skill), to_chinese(skill) ) );
				}*/
			}
			me->receive_damage( "gin", gin_cost );
		}
		else
			return notify_fail ("你今天太累了﹐結果什麼也沒有學到。\n");
	}

	if( r == 1 )
		printf( "你聽了%s的指導﹐似乎有些心得。\n", ob->name() );

	return 1;
}

int help( object me )
{
        write(@HELP
指令格式 : learn <技能> from <某人>
指令說明 :
           這個指令可以讓你向別人請教有關某一種技能的疑難問
     題﹐當然﹐你請教的對象在這項技能上的造詣必須比你高﹐而
     你經由這種方式學習得來的技能也不可能高於你所請教的人﹐
     然而因為這種學習方式相當於一種「經驗的傳承」﹐因此學習
     可以說是熟悉一種新技能最快的方法。
           通常﹐一個人剛學到一種新技能是不會有什麼疑難問題
     的﹐而是經由實際上的應用中遭遇問題﹐這些問題對於學習一
     種新技能的過程是很重要的﹐尤其是各種作為其他技能基礎的
     基本技能﹐更需要經由「發現問題─解決問題」的過程才能得
     到較好的效果。因此我們將這種發現問題的過程用「潛能」的
     觀念表示﹐一個人能夠自己發現某些問題﹐表示他(她)有解決
     這項問題的潛能﹐當你具有這樣的潛能時就可以利用這個指令
     來向其他人請教﹐而獲得進步。
           學習需要消耗一些精力﹐而消耗的精力跟你自己、與你
     學習對象的悟性有關。
           至於如何知道你能從對方學到什麼技能﹐如果對方是你
     的師父﹐可以用 skills 指令直接查看﹐如果不是你的師父﹐
     那麼通常會有其他的提示﹐你只好自己想辦法。
其他參考 :
           practice、study
     補充說明:你可以打learn 10 技能名稱 from master......
         其效果相等於learn force from master...十次.....
         可以節省系統資源........

HELP );
        return 1;
}
