// 新增南蠻war 凌雪飛
#include <ansi.h>
inherit NPC;
string ask_crystal();
string magic1();
string magic2();
string magic3();
string ask_array();
string ask_ice();
string ask_fire();

void create()
{
            set_name("凌雪飛",({"fly dancer","fly","dancer"}) );
            set("long","她是月牙兒的師姐，擅長媚術，據說她已經領悟出夜夢天舞的終極殺\n招，當年因為心術不正而被逐出師門，但是她的修為似乎比月牙兒更\n高，以舞媚之術稱霸南蠻數年無人能敵。\n");
            set("gender","女性");
            set("class","dancer");
            set("nickname",HIM + "舞" + HIW + "之" + HIG + "傳人" + NOR);
            set("combat_exp",7000000);
            set("attitude","heroism");
            set("age",26);
            set("str", 99);
            set("cor", 99);
            set("int", 99);
            set("spi", 99);
            set("cps", 99);
            set("per", 99);
            set("con", 99);
            set("kar", 99);
            set("kee",150000);
            set("gin",40000);
            set("sen",40000);
            set("atman",40000);
            set("mana",40000);
            set("force",150000);
            set("max_kee",150000);
            set("max_gin",40000);
            set("max_sen",40000);
            set("max_mana",40000);
            set("max_atman",70000);
            set("max_force",200000);
            set_skill("parry",120);
            set_skill("unarmed",160);
            set_skill("move",120);
            set_skill("dodge",120);
            set_skill("magic",160);
            set_skill("spells",160);
            set_skill("force",250);
            set_skill("paull-steps",130);
            set_skill("dremagic",100);
            set_skill("dreamdance",100);
            set_skill("necromancy",100);
            set_skill("dreamforce",200);
            map_skill("unarmed","dreamdance");
            map_skill("parry","dreamdance");
            map_skill("dodge","paull-steps");
            map_skill("move","paull-steps");
            map_skill("force","dreamforce");
            map_skill("spells","necromancy");
            map_skill("magic","dremagic");
            set_temp("apply/armor",100);
            set_temp("ref_shield",1);
            set("spells/reflection/level",100);
            set("spells/fdragon/level",100);
            set("spells/fireball/level",100);
            set("spells/confuse/level",100);
            set("spells/thunder/level",100);
            set("spells/firedance/level",100);
            set("spells/hellfire/level",100);
            set("spells/dreamwings/level",100);
            set("spells/dreamcure/level",100);
            set("spells/meteor/level",100);
            set("get_dan_sp",1);
            set("allow_meteor",1);
            set("adv_dancer",1);
            set("allow_fdragon",1);
            set("allow_hellfire",1);
            set("force_factor",15);
            set_temp("roared", 1 );
            setup();
            set("chat_chance",100);
            create_family("夜夢小築",3,"鳳凰傳人");
            carry_object("/open/dancer/obj/linrboots.c")->wear();
            carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
            carry_object("/open/dancer/obj/yuawaist.c")->wear();
            set("chat_chance_combat",60);
                    set("inquiry", ([
            "渾天水晶" :  (: ask_crystal :),
            "薛霸天"   :  "南蠻三霸之一，是我很好的朋友，但跟我一樣也是仇家很多，所以他行蹤也不定。",
            "四無之陣" :  (: ask_array   :),
            "冰之紋章" :  (: ask_ice     :),
            "炎之紋章" :  (: ask_fire    :),
            ]));
            set("chat_msg_combat",({
             (: magic1 :),
             (: magic2 :),
             (: magic3 :),
            }));
}

//molecule 有關寒冰烈火掌

int greeting()
{    
    object me=this_player();
    if ( me->query_temp("ask_ice_fire") == 9 && present("fire-medal",me) )
    tell_object(me,"\n是段雲給你" + HIR + "炎之紋章" + NOR + "的吧? 之前遊至平南城時，剛好遇到仇家追殺，匆促離開的情形下將此物品交給了段雲。\n" + NOR);

    if ( me->query_temp("ask_ice_fire") == 9 && present("ice-medal",me) )
    tell_object(me,"\n是慕容復給你" + HIC + "冰之紋章" + NOR + "的吧? 之前遊至西域時，剛好遇到仇家追殺，匆促離開的情形下將此物品交給了慕容復。\n" + NOR);
}

string ask_fire()
{
    object me=this_player();
    if ( me->query_temp("ask_ice_fire") == 9 && present("fire-medal",me) )
    {
       me->set_temp("allow_search",1);
       return("炎之紋章如果沒和冰之紋章一起使用的話，是沒有任何作用的，所以你的另一個夥伴必須要去尋找冰之紋章。\n");
    }
    if ( me->query_temp("ask_ice_fire") == 9 && present("ice-medal",me) )
    return("炎之紋章可能需要雪蒼派的同伴去尋找了，這兩樣物品是進入四無之陣的關鍵。\n");
}

string ask_ice()
{
    object me=this_player();
    if ( me->query_temp("ask_ice_fire") == 9 && present("ice-medal",me) )
    {
       me->set_temp("allow_search",1);     
       return("冰之紋章如果沒和炎之紋章一起使用的話，是沒有任何作用的，所以你的另一個夥伴必須要去尋找炎之紋章。\n");
    }
    if ( me->query_temp("ask_ice_fire") == 9 && present("fire-medal",me) )
    return("冰之紋章可能需要瀧山派的同伴去尋找了，這兩樣物品是進入四無之陣的關鍵。\n");
}

string ask_array()
{
    object me=this_player();
    if ( me->query_temp("ask_ice_fire") == 9 && me->query("family/family_name") == "雪蒼派" )
    {
       me->set_temp("ask_ice_fire",10);
       return("我從薛霸天那邊聽說過，要修練寒冰烈火掌必須改變你自身的體質，但要改變
            自身的體質談何容易，好在我曾經問過薛霸天，他告訴我必須取得四無之陣中
            的龍鐵心，這是他當初封印在四無之陣內的物品，要破此陣需要一位瀧山派的
            同伴和你同行，兩個人身上必須要有炎之紋章和冰之紋章才能入陣，至於四無
            之陣的入口，就在這附近，取得龍鐵心後再來找我吧。\n");
    }
    if ( me->query_temp("ask_ice_fire") == 9 && me->query("family/family_name") == "瀧山派" )     {   
       me->set_temp("ask_ice_fire",10);       return("我從薛霸天那邊聽說過，要修練寒冰烈火掌必須改變你自身的體質，但要改變
            自身的體質談何容易，好在我曾經問過薛霸天，他告訴我必須取得四無之陣中
            的明月心，這是他當初封印在四無之陣內的物品，要破此陣需要一位雪蒼派的
            同伴和你同行，兩個人身上必須要有冰之紋章和炎之紋章才能入陣，至於四無
            之陣的入口，就在這附近，取得明月心後再來找我吧。\n");
    }
}

int accept_object(object me,object obj)
{
    me=this_player();
}
 
//
      
int accept_kill(object who)
{
    who=this_player();
    command("con reflection");
    kill_ob(who);
message_vision(sprintf("\n\t\t" + HIC + "    " + HIW + "～　" + HIM + "憶紅塵" + HIW + "，" + HIG + "血染霓裳" + HIW + "，" + HIY + "天地無痕各一方\n\n\n"
HIC + "\t\t\t無奈何" + HIW + "，" + HIB + "恨遺飛霜" + HIW + "，" + HIR + "孤獨人間恨兩行　" + HIW + "～\n\n\n"
HIR + "\t ╭═╮  ╭╗      " + HIG + "╠╦╦╦╦╯    " + HIC + "═╗╭══╮    " + HIM + "◆╭═╮╭═╮\n"
HIR + "\t ╠═╣╰═╝      " + HIG + "╰╬╬╬╬╯    " + HIC + "╰╯║╭╮║    " + HIM + "◆╠─╣╠─╣\n"
HIR + "\t ╰╦╯  ╭╗      " + HIG + "╰╬╩╩╩╯     " + HIC + "● ║║║║    " + HIM + "╗╠═╯╰═║\n"
HIR + "\t ╦╩╦╰═╯        " + HIG + "╠═╦╬╯     " + HIC + "╗ ║║║║    " + HIM + "║║ ╦╬╦ ║\n"
HIR + "\t ╰╦╯  ╭╗        " + HIG + "║●╬╬╯     " + HIC + "║ ║╰╯║    " + HIM + "║║ ╰︾╯ ║\n"
HIR + "\t ●║●╰═╯        " + HIG + "╯  ║║       " + HIC + "╯ ╰══╯  " + HIM + "╰╝║ ╭╬╮ ║\n\n\n"),this_player());
    who->start_busy(1);
    return 1;
}

void heart_beat()
{
 object env,mob,*enemy;
 int i,j,k;
 j=random(100);
 mob = this_object();
 if(!mob) return ;
 if(!environment(mob)) return ;
 env = environment(mob);
 if( j < 40 && is_fighting())
 {
message_vision(HIW + "\n\n\t\t----- " + HIY + "媚 " + HIW + "＊ " + HIG + "影 " + HIW + "＊ " + HIR + "舞 " + HIW + "＊ " + HIC + "豔" + HIW + " -----\n\n"
HIM + "$N" + HIM + "眼露媚光，隨著夜色迷濛翩翩起舞，朱唇嬌豔，舞姿輕盈，此招正是\n"
HIM + "$N" + HIM + "傾國傾城，迷惑天下的妖媚之術，你受到媚術所迷惑，看的入迷三分\n
不知不覺逐漸被媚術迷惑失神，攻防之值瞬間大降！\n\n" + NOR, mob );
  for( k=0 ; k < i ; k++)
   {
   if( !enemy[k] ) continue;
    if( enemy[k]->is_character() && !enemy[k]->is_corpse() && living(enemy[k]) && enemy[k] != mob && !wizardp(enemy[k]) )
     {
      message_vision(HIR + "妖媚之術如天仙下凡，看得你如癡如醉，目瞪口呆！！\n" + NOR,enemy[k]);
      enemy[k]->receive_wound("kee",200);
      enemy[k]->apply_condition("power-down",enemy[k]->query_condition("power-down")+5);
      COMBAT_D->report_status(enemy[k]);
     }
   }
 }

    if( 40 < j && j < 70 && is_fighting() )
        {
        enemy=mob->query_enemy();
        for(i=0;i<sizeof(enemy);i++){
        if(!enemy[i]) continue;
    if(environment(mob) == environment(enemy[i]))
        {
    message_vision(HIR + "\n\n$N運起鳳凰靈氣，靈氣灌頂游走全身，鳳凰靈氣配合夢玄法鑑，空氣瞬間凝結成冰！\n\n"
HIC + "\t\t\t◎ "HBBLU+HIR"鳳 " + HIW + "～ " + HIR + "凰 " + HIW + "～ " + HIY + "展 " + HIW + "～ " + HIY + "翅"NOR+HIC" ◎\n\n"
HIB + "\t\t● " + HIR + "血 " + HIW + "、 " + HIR + "染 " + HIW + "、 " + HIM + "紅 " + HIW + "、 " + HIM + "塵 " + HIW + "、 " + HIG + "舞 " + HIW + "、 " + HIG + "秋 " + HIW + "、 " + HIG + "風 " + HIB + "●\n\n\n"
HIY + "只見$N" + HIY + "身上散放出一股強大的氣勁，靈氣頓時浮現衝天而去，化成八道不同的靈光疾射\n"
HIY + "你胸前八大要穴，只見你" + HIY + "受靈氣所限制，頓時全身內力不斷流失，身體虛弱無力，無法使勁。\n\n" + NOR, mob );
    enemy[i]->apply_condition("no_power_e",random(10)+5);
    enemy[i]->receive_damage("kee", 800 );
    enemy[i]->receive_damage("gin", 300 );
    enemy[i]->receive_damage("sen", 300 );
    COMBAT_D->report_status(enemy[i]);

    }
   }
  }

    if( 70 < j )
    {mob->delete_busy();
        if(mob -> query("kee") < mob->query("max_kee")*0.6)
        {
    message_vision( HIG + "\n$N" + HIG + "使出夢玄法鑑治療術，瞬間身上的傷口漸漸癒合。\n" + NOR, mob);
    mob->clear_condition();
    mob->receive_heal("kee",700);
    mob->receive_curing("kee",700);
    mob->receive_heal("gin",500);
    mob->receive_curing("gin",500);
    mob->receive_heal("sen",500);
    mob->receive_curing("sen",500);
    }
    }

   set_heart_beat(1);
   ::heart_beat();

}


string magic1()
{
if(random(2)<1)
command("con firedance");
else command("con confuse");
return "\n";
}

string magic2()
{
if(random(2)<1)
command("con hellfire");
else command("con thunder");
return "\n";
}

string magic3()
{
if(random(3)<2)
command("con fdragon");
else command("con fireball");
return "\n";
}


void die()
{
    object winner = query_temp("last_damage_from");
    string name = winner->query("name");
    int c = random(4);
    if(!winner)
    {
    ::die();
    return ;
    }
          if(winner->query_temp("find_crystal") == 17 )
            {                   
             winner->set_temp("find_crystal",18);
             new("/open/prayer/obj/crystal7.c")->move(winner);
             new("/open/prayer/obj/crystal8.c")->move(winner);
             new("/open/prayer/obj/crystal9.c")->move(winner);
             new("/open/prayer/obj/crystal10.c")->move(winner);
             message_vision(HIW + "\n\n$N從凌雪飛身上得到了四根渾天水晶。\n\n" + NOR,winner);
            }else if(winner->query_temp("find_crystal"))
                    {
                     winner->set_temp("find_crystal",18);
                     if(c == 0)  new("/open/prayer/obj/crystal7.c")->move(winner);
                     if(c == 1)  new("/open/prayer/obj/crystal8.c")->move(winner);
                     if(c == 2)  new("/open/prayer/obj/crystal9.c")->move(winner);
                     if(c == 3)  new("/open/prayer/obj/crystal10.c")->move(winner);
                     message_vision(HIW + "\n\n$N從凌雪飛身上得到了一根渾天水晶。\n\n" + NOR,winner);
                    }
    ::die();
}

string ask_crystal()
{
  object user = this_player();
  if(user->query_temp("find_crystal"))
  {
    if(user->query_temp("find_crystal") != 16)
    {
     kill_ob(user);
     user->set_temp("find_crystal",18);
     return "想要水晶嗎，去跟閻羅王拿吧。";     
    }else{
         user->set_temp("find_crystal",17);
         return "想要水晶??  有本事儘管來拿啊。";
         }
  }
        
}
