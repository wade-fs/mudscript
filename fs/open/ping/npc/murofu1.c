// copy from konn,re-edit from ccat 
//加強慕容復使用各派進階技的能力與避免玩家使用賤招 by cyw 91/03/19
#include <ansi.h>
inherit NPC;
object fu_weapon;
int have_weapon=0;
void create()
{
        set_name("慕容復", ({"murofu"}));
        set("title", HIB + "以彼之道 "+HIC+"還彼之身" + NOR);
        set("long", "蘇杭名士慕容復,善各家武功,乃江南第一高手.\n");
        set("age", 40);
        set("str", 35);
        set("con", 35);
        set("spi", 35);
        set("cor", 35);
        set("cps", 35);
        set("per", 35);
        set("int", 35);
        set("kar", 35);
        set("env/狂擊","YES");
        set("env/連擊",1);
        set("env/六絕劍","YES");
        set("env/魔性六斬","YES");
        set("max_kee", 50000);
        set("kee", 50000);
        set("max_gin", 50000);
        set("gin", 50000);
        set("max_sen", 50000);
        set("sen", 50000);
        set("force", 20000);
        set("max_force", 20000);
        set("force_factor", 10);
        set("combat_exp", 500000);
        set("s_kee",500);
        set("max_s_kee",500);
        set("sec_kee","mkill");
        set("gender", "男性");
        set("score",5000000);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("force", 250);
        set_skill("unarmed", 100);  
        set_skill("snow-martial", 100);
        set_skill("snow-kee", 100);
        set_skill("snowforce", 200);
        set_skill("blackforce", 200);
        set_skill("badforce", 200);
        set_skill("sixforce", 200);
        set_skill("haoforce", 200);
        set_skill("iceforce", 200);
        set_skill("linpo-steps", 100);
        set_skill("shade-steps", 100);
        set("dragon-sword",1);
        set("quests/read_snow",3);
        set("quest/rain",1);
        set("quest/memory",1);
        set("quest/head-kill",1);
        set("quest/worldpill",1);
        set("marks/six_sp",3);
        set("get_sha_sp",1);
        set("super_fire",1);
        set("fire_strike",1);
        map_skill("unarmed", "snow-martial");
        map_skill("parry", "snow-kee");
        map_skill("dodge", "linpo-steps");
        map_skill("move", "linpo-steps");
        map_skill("force", "snowforce");
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 90);
        set_temp("apply/defense",90);
        set_temp("apply/dodge", 20);
        set_temp("apply/parry", 50);
        set_temp("final-attack",3);
        set("functions/sha_kee/level",100);
        set("functions/gold-dest/level",100);        
        set("functions/ice-fingers/level",100);        
        set("functions/handwriting/level",100);
        set("functions/manakee/level",100);
        set("chat_chance_combat", 100);
        set("chat_msg_combat",({
           (: perform_action("stabber.handwriting") :),
           (: perform_action("sword.sha_kee") :),
           (: perform_action("blade.gold-dest") :),
           (: perform_action("snow-martial.ice-fingers") :),
      }));
        setup();
       carry_object("/open/ping/obj/poison_pill")->set_amount(3);  
       add_money("gold",25);
}
void init()
{
	::init();
	add_action("block_cmd","");
}

int block_cmd(string arg)           
{
	if(((string)query_verb()=="enable" ||          //為了防止用賤招打murofu,在戰鬥中禁止使用enable指令
	    (string)query_verb()=="en" ||
	    (string)query_verb()=="ena" ||
	    (string)query_verb()=="enab" ||
	    (string)query_verb()=="enabl")&& this_player()->is_fighting()){
		write(HIY + "面對慕容復的快攻，你毫無機會換招\n" + NOR );
		return 1;}
//	else if((string)query_verb()=="co" ||           //於心跳中加強對dancer與taoist故暫時取消對法術的限制
//	        (string)query_verb()=="con" ||
//	        (string)query_verb()=="conj" ||
//	        (string)query_verb()=="conju" ||
//	        (string)query_verb()=="conjur" ||
//	        (string)query_verb()=="conjure" ||
//	        (string)query_verb()=="ca" ||
//	        (string)query_verb()=="cas" ||
//	        (string)query_verb()=="cast"){
//	            write(HIY + "慕容復身上的天尊石發出耀眼光芒使敵人的法術失效了\n" + NOR );
//               return 1;}
       else if((string)query_verb()=="team") {          //為了防止用賤招打murofu,禁止使用team指令
	            write(HIY + "以多欺寡不太好吧!!\n" + NOR );
	       return 1;}
       else if((string)query_verb()=="steal") {          //為了防止用賤招打murofu,禁止使用steal指令
	            write(HIY + "慕容復怒道：憑你這點本領也想從我手上偷東西？\n" + NOR );
	       return 1;}
       else if((string)query_verb()=="cm" ||	         //為了防止用賤招打murofu,禁止使用cmd指令
	        (string)query_verb()=="cmd") {
	            write(HIY + "慕容復怒道：這種濫招對我是沒用的\n" + NOR );
	       return 1;}
       else if((string)query_verb()=="unwield" && this_player()->is_fighting()) {	//為了防止用賤招打murofu,在戰鬥中禁止使用unwield指令        
	       	    write(HIY + "慕容復怒道：想棄械投降？別想\n" + NOR );
	       return 1;}       
       else if(((string)query_verb()=="dro" ||               //為了防止用賤招打murofu,在戰鬥中禁止使用drop指令
               (string)query_verb()=="drop") && this_player()->is_fighting()) {	        
	       	    write(HIY + "你無法在此時丟掉任何物品\n" + NOR );
	       return 1;}
       else if((string)query_verb()=="wield" && this_player()->is_fighting()) {      //為了防止用賤招打murofu,在戰鬥中禁止使用wield指令
	            write(HIY + "你找不到使用武器的機會\n" + NOR );
	       return 1;}
}
int accept_kill(object me)
{   
//    me->start_busy(1);   
    if(! is_fighting()){
       this_object()->set_temp("exp",me->query("combat_exp"));
       call_out("change",1,me);  
    }
    else if(this_object()->query("combat_exp") < me->query("combat_exp")){
       this_object()->set_temp("exp",me->query("combat_exp"));
       call_out("change",1,me); 
    }   
    return 1;
}
int accept_fight(object me)
{
//    me->start_busy(1);  
   if(! is_fighting()){
       this_object()->set_temp("exp",me->query("combat_exp"));
       call_out("change",1,me);  
    }
    else if(this_object()->query("combat_exp") < me->query("combat_exp")){
       this_object()->set_temp("exp",me->query("combat_exp"));
       call_out("change",1,me); 
    }   
    return 1;
}


int change( object me )
{    	
    	object weapon = me->query_temp("weapon");
        string skill, m_skill,class1,family1;
        int lv_1, lv_2, exp,ffactor;          
        if( !have_weapon )
        {
          have_weapon = 1;
          fu_weapon = new("/open/ping/obj/fu_weapon");
          fu_weapon->move(this_object());
          fu_weapon->set("skill_type","unarmed");
          fu_weapon->set("material","crimsonsteel");     //只有murofu拿才是這種材質不會被砍斷,murofu死後恢復為普通鋼材
         }
           
        if( weapon ) skill = weapon->query("skill_type");
        else skill = "unarmed";
        
        lv_1 = me->query_skill(skill, 1);
        if (lv_1 < 80)
        lv_1 = 80;
        set_skill(skill, lv_1);

        m_skill = me->query_skill_mapped(skill);
        if( m_skill )
        {    
          say("慕容復說: 你使的是"+to_chinese(m_skill)+"吧! 哼! 我就用它來"
              +"對付你!!\n");
          lv_2 = me->query_skill(m_skill, 1);
          if (lv_2 < 80)
          lv_2 = 80;
          set_skill(m_skill, lv_2);
          map_skill(skill,m_skill);
          command("change "+skill); 
          command("unwield all");         //光set skill_type無法使murofu變換武功,故需unwield再wield
          command("wield specail");       
            }else{
           say("慕容復說: 自大的傢伙,不運功也想打敗我!! 去死吧!!\n");
        }
        exp = 1.2 * me->query("combat_exp");
       	if(exp > 500000)
       	set("combat_exp", exp);    
       	set_skill(me->query_skill_mapped("force"),200);
       	map_skill("force",me->query_skill_mapped("force"));   
       	set_skill(me->query_skill_mapped("dodge"),100);
       	map_skill("dodge",me->query_skill_mapped("dodge"));              
        ffactor = me->query("force_factor");
        class1 = me->query("class");
        family1 = me->query("family/family_name");
        if(skill=="archery"){                         //如果用箭術必需在fu_weapon set 箭的數量,不然無法出招
        	weapon->set("arrow/id","Plum arrow");
                weapon->set("arrow/name","折梅箭");
                weapon->set("weapon_prop/damage",100);
                weapon->set("arrow/amount",300);
        }
        set("class",class1);
        set("family/family_name",family1);
        if(ffactor > 10)
        set("force_factor",ffactor);
        set("bellicosity",me->query("bellicosity"));
/* if( weapon && (weapon->query("id")=="dragon blade" ||  //如果敵人持有特殊攻擊武器就加強自身防禦(使用reflection)
				weapon->query("id") =="et-sword" ||
				weapon->query("id")=="evil-mblade" ||
				weapon->query("id")=="ublade" ||
				weapon->query("id")=="iceblade" ||
				weapon->query("id")=="sun_moon blade" ||
				weapon->query("id")=="world") )
       	  {
     	  say(HIY + "慕容復說: 竟拿此神兵利器，看我玄冰護體!!\n" + NOR);
	  set_temp("ref_shield",1);
      }  */
        setup();
        return 1;
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	object fu_weapon = query_temp("weapon");
	int j;
	if(fu_weapon)
	fu_weapon->set("material","steal");  //死前把百變奇扇還原成普通鋼材
        if(!winner)
	{
	::die();
	return ;
        }
        winner->set_temp("kill_murofu",1);
/*        if(userp(winner)) {
	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {      
	  new("/open/sky/obj2/sky_stone")->move(environment(winner));
	  message_vision(HIM + "\n從慕容復的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj2/sky_stone",sprintf("%s(%s) 讓慕容復掉下了天尊石於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj2/sky_stone")->move(environment(winner));
	  message_vision(HIM + "\n從慕容復的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj2/sky_stone",sprintf("%s(%s) 讓慕容復掉下了天尊石於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
        }*/
	::die();                                                           
}

void heart_beat()
{
	mapping	exit;
	string	*exit_name;
	object	weapon, *enemy;
	int	i, j , k, atman, mana;

	if( query("kee") < 0 ) {
		die();
		return;
	}
           
	if( is_fighting() ) {          //要判斷戰鬥中的事件都寫在這
		if( query("kee")*100/query("max_kee") < 25 ) {         //自動逃跑
			exit_name = keys(environment()->query("exits"));
			i = sizeof(exit_name);
			command(exit_name[random(i)]);
			command(exit_name[random(i)]);
		}

		enemy = query_enemy();
		k = 0;
		for( i=0, j = sizeof(enemy); i < j; i++ ) {          //確認敵人中是否還有人拿特殊武器
		    if(enemy[i]){	
			weapon = enemy[i]->query_temp("weapon");
			if( weapon && (weapon->query("id")=="dragon blade" ||
				weapon->query("id") =="et-sword" ||
				weapon->query("id")=="evil-mblade" ||				
				weapon->query("id")=="sun_moon blade" ||
				weapon->query("id")=="world") )
				k++;
			if(((enemy[i]->query("class")== "killer" ||     //針對殺手與惡人增加功擊
			    enemy[i]->query("class")== "bandit") && random(10)<3) && environment(this_object())==environment(enemy[i])) {
		                say(HIR + "\n\n慕容復狂傲的說道: 邪門歪道看我慕容家絕學"+HIB + "『以彼之道 "+HIC+"還彼之身』\n\n" + NOR);
                                message_vision(HIG + "幕容復自家內力一催，將$N招式中攻擊的力道納為己用，頓時龍氣集結於上空往$N位置迅速衝去\n\n" + NOR,enemy[i]);
                                if((enemy[i]->query_kar()+enemy[i]->query_cps()) < random(150)){
                                    message_vision(HIR + "$N慘遭自己招式所幻化之龍氣反蝕\n\n" + NOR,enemy[i]);
                                    if((enemy[i]->query("force_factor")-5)>0)
                                        enemy[i]->add("force_factor",-5);
                                    else enemy[i]->set("force_factor",0);
                                    enemy[i]->receive_wound("kee",random((int) enemy[i]->query("max_kee")* 0.2),this_object());
                                    COMBAT_D->report_status(enemy[i],0);
                                }else
                                    message_vision(HIW + "$N凝氣定神竟好運的躲過此招\n\n" + NOR,enemy[i]);
                        }            
                        if(((enemy[i]->query("class")== "dancer" ||     //針對法術系門派增加功擊
			    enemy[i]->query("class")== "taoist") && random(10)<3) && environment(this_object())==environment(enemy[i])) {
		                say(HIR + "\n\n慕容復狂傲的說道: 別以為使用法術我就拿你沒輒，看我家傳秘寶"+HIY + "『天尊石』\n\n" + NOR);
                                message_vision(HIG + "拿出天尊石，頓時天地無光，似乎天地萬物所有的靈氣都被天尊石給吸盡了\n\n" + NOR,enemy[i]);
                                if((enemy[i]->query_kar()+enemy[i]->query_cps()) < random(150)){
                                    message_vision(HIR + "$N被天尊石所吸引，身上靈氣不斷外洩\n\n"+
                                                   MAG + "慕容復口中喃喃道著咒語瞬間一道皓光從天尊石射出往$N疾飛而去\n\n" + NOR,enemy[i]);
                                    atman= -(int) enemy[i]->query("max_atman")*0.4;
                                    mana= -(int) enemy[i]->query("max_mana")*0.4;  
                                    if((enemy[i]->query("atman")+atman)>0)                                         
                                        enemy[i]->add("atman",atman);                                        
                                    else enemy[i]->set("atman",0);                                    
                                    if((enemy[i]->query("mana")+mana)>0)                                        
                                        enemy[i]->add("mana",mana);
                                    else enemy[i]->set("mana",0);
                                    enemy[i]->receive_wound("kee",random((int) enemy[i]->query("max_kee")* 0.3),this_object());
                                    COMBAT_D->report_status(enemy[i],0);
                                    enemy[i]->start_busy(2);
                                }else
                                    message_vision(HIW + "$N凝氣定神竟好運的躲過此光束的攻擊\n\n" + NOR,enemy[i]);
		}	   	
		}	   
                }
//                 if(k > 0 || sizeof(enemy) > 1)
//                     set_temp( "ref_shield", 1 );
//            else if( query_temp("ref_shield") == 1 )
//                 delete_temp("ref_shield");
	        if(is_busy() && random(10)<3){
	        	delete_busy();
	                message_vision(HIC + "\n\n慕容復全身泛起紫氣衝開了被封的穴道\n\n" + NOR,this_object());
	        }
	                  	        	
	}
	else if( query_temp("ref_shield") == 1 )
		delete_temp("ref_shield");


// 有十次補精氣神的機會, kee < 60% 補
	if( query_temp("heal") < 10 )
		if( query("kee")*100/query("max_kee") < 60 ||
		    query("gin")*100/query("max_gin") < 60 ||
		    query("sen")*100/query("max_sen") < 60) {
			receive_curing( "kee", 2000 );
			receive_heal( "kee", 2000 );
			receive_curing( "gin", 2000 );
			receive_heal( "gin", 2000 );
			receive_curing( "sen", 2000 );
			receive_heal( "sen", 2000 );
			delete_busy();
			add_temp( "heal", 1 );
			tell_room( environment(), HIW + name() +
				"使出家傳絕學, 簡簡單單地治好自己的傷口。\n" + NOR );
		}
	if(!is_fighting())
	remove_all_killer();      //讓murofu不會記恨
	::heart_beat();
}

