inherit SKILL;
#include <ansi.h>
#include <combat.h>

void poem1 (object me, object target, object weapon, int damage);
void poem2 (object me, object target, object  weapon, int damage);
void poem3 (object me, object target, object  weapon, int damage);
void delay (object me, object target, object  weapon, int damage);

mapping *action = 
({
//1
	([	"action" :  
		HIW + "\t\t\t－－－《　" + HIR + "定　　風　　波　" + HIW + "》－－－ " + NOR + "

\t\t        " + HIM + "莫聽穿林打葉，何妨吟嘯且徐行。
\t\t        竹杖芒鞋輕勝馬。誰怕？一蓑煙雨任平生。
\t\t        料峭春風吹酒醒，微冷、山頭斜照卻相迎。
\t\t        回首向來蕭瑟處，歸去、也無風雨也無晴。\n" + NOR,
	
		"damage_type"	:	"劍傷",
		"damage"		:	1000,
		"force"			:	100,

	]),
//2
	([  "action" :
    		HIW + "\t\t\t－－－《　" + HIC + "釵　　頭　　鳳 " + HIW + "》－－－ " + NOR + "
		
\t\t        " + CYN + "紅酥手，黃滕酒，滿城春色宮牆柳。
\t\t        東風惡，歡情薄，一懷愁緒，幾年離索。
\t\t        錯、錯、錯。
		
\t\t        春如舊，人空瘦，淚\痕紅浥鮫綃透。
\t\t        桃花落，閒池閣，山盟雖在，錦書難託。
\t\t        莫、莫、莫。　\n" + NOR,

		"damage_type"	:	"劍傷",
		"damage"		:	700,
		"force"			:	100,

	]),
//3
	([  "action" :
            HIW + "\t\t\t－－－《　" + HIG + "上　　邪　" + HIW + "》－－－   " + NOR + "
		
\t\t        " + GRN + "上邪！我欲與君相知，長命無絕衰！
\t\t        山無陵，江水為竭，冬雷震震！
\t\t        夏雨雪，天地合，乃敢與君絕！\n" + NOR,

		"damage_type"	:	"劍傷",
		"damage"		:	800,
		"force"			:	100,
	]),
//4
	([	"action" :
	     	HIW + "\t\t\t－－－《　" + HIY + "一　　剪　　梅　" + HIW + "》－－－" + NOR + "   

\t\t        " + YEL + "花自飄零水自流。
\t\t        一種相思，二處閒愁。
\t\t        情無計可消除，
\t\t        才下眉頭，卻上心頭。\n" + NOR,

		"damage_type"	:	"劍傷",
		"damage"		:	500,
		"force"			:	50,
	]),
//5
	([	"action" :
    		HIW + "\t\t\t－－－《　" + HIB + "題　　西　　林　" + HIW + "》－－－   
		
\t\t        " + HBMAG + "" + HIW + "橫看成嶺側成峰，" + NOR + "
\t\t        " + HBMAG + "" + HIW + "遠近高低各不同，" + NOR + "
\t\t        " + HBMAG + "" + HIW + "不識廬山真面目，" + NOR + "
\t\t        " + HBMAG + "" + HIW + "只緣身在此山中。\n" + NOR,

		"damage_type"	:	"劍傷",
		"damage"		:	800,
		"force"			:	50,
	]),
//6
    ([	"action" :
		HIW + "\t\t\t－－－《　" + HBRED + "" + HIW + "登　金　陵　鳳　凰　臺" + NOR + "　" + HIW + "》－－－   

\t\t        " + NOR + "" + HIR + "鳳凰臺上鳳凰遊，鳳去臺空江自流。
\t\t        吳宮花草埋幽徑，晉代衣冠成古丘。
\t\t        三山半落青天外，二水中分白鷺洲。
\t\t        總為浮雲能蔽日，長安不見使人愁。\n" + NOR,

		"damage_type"		:	"劍傷",
		"damage"			:	500,
		"force"				:	30,
	]),
//7
    ([	"action" :
	    HIW + "\t\t\t－－－《　" + CYN + "" + HIW + "將　　進　　酒" + NOR + "　" + HIW + "》－－－   

\t\t        " + NOR + "" + BLU + "君不見黃河之水天上來，奔流到海不復回？
\t\t        君不見高堂明鏡悲白髮，朝如青絲暮成雪？
\t\t        人生得意須盡歡，莫使金樽空對月。
\t\t        天生我材必有用，千金散盡還復來。\n" + NOR,

		"damage_type"		:	"劍傷",
		"damage"			:	500,
		"force"				:	50,
	]),
//8
	([	"action" :
		HIW + "\t\t\t－－－《　" + HBCYN + "" + GRN + "月　　下　　獨　　酌" + NOR + "　" + HIW + "》－－－   

\t\t        " + NOR + "" + HBMAG + "" + BLK + "花間一壺酒，獨酌無相親；" + NOR + "
\t\t        " + HBMAG + "" + BLK + "舉杯邀明月，對影成三人。" + NOR + "
\t\t        " + HBMAG + "" + BLK + "月既不解飲，影徒隨我身；" + NOR + "
\t\t        " + HBMAG + "" + BLK + "暫伴月將影，行樂須及春。" + NOR + "
\t\t        " + HBMAG + "" + BLK + "我歌月徘徊，我舞影零亂；" + NOR + "
\t\t        " + HBMAG + "" + BLK + "醒時同交歡，醉後各分散。" + NOR + "
\t\t        " + HBMAG + "" + BLK + "永結無情遊，相期邈雲漢。\n" + NOR,

		"damage_type"		:	"劍傷",
		"damage"			:	800,
		"force"			:	80,
	]),
//9
    ([  "action" :
		HIW + "\t\t\t－－－《　" + HBYEL + "" + HIW + "黃　　鶴　　樓" + NOR + "　" + HIW + "》－－－   

\t\t        " + HIC + "昔人已乘黃鶴去，此地空餘黃鶴樓。
\t\t        黃鶴一去不復返，白雲千載空悠悠。
\t\t        晴川歷歷漢陽樹，芳草萋萋鸚鵡洲。
\t\t        日暮鄉關何處是？煙波江上使人愁。\n" + NOR,

		"damage_type"		:	"劍傷",
		"damage"			:	600,
		"force"				:	50,
	]),
//10
    ([  "action" :
		HIW + "\t\t\t－－－《　" + HBRED + "" + HIM + "聲　　聲　　慢" + NOR + "　" + HIW + "》－－－   

\t\t        " + NOR + "" + CYN + "尋尋覓覓，冷冷清清，悽悽慘慘戚戚。
\t\t        乍暖還寒時候，最難將息。
\t\t        三杯兩盞淡酒，怎敵他，曉來風急。
\t\t        雁過也，最傷心，卻是舊時相識。\n" + NOR,

		"damage_type"		:	"劍傷",
		"damage"			:	500,
		"force"				:	50,
		"post_action"		: (: poem1 :),
	]),
//11
    ([  "action" :
		"
\t\t	                 " + GRN + "▁▃▂▄▅▃▁    " + HIW + "∩︵∩" + NOR + "
\t\t    " + GRN + "   ▄▅▃▂▁     ﹊﹊  ▔﹊﹊﹊ " + HIW + "（      ）" + NOR + "    
\t\t    ﹊▔﹊﹊  ﹊﹊ " + CYN + "﹀           " + HIY + "-──" + HIW + "（   ∫ ）" + NOR + "
\t\t                          " + CYN + "﹀    " + HIY + "|   " + HIB + "▕▔▔▔▔▔   
\t\t             " + HIG + "▁▅▇█▇▅▁     " + HIY + "|  " + HIB + "▕▔▔▔▔▏
\t\t           " + CYN + "- _ ﹊﹊" + HIC + "-_﹊-﹊" + NOR + "" + CYN + "﹊_   " + HIY + "|  " + HIB + "▕ ▕▔▔▔▏   
\t\t           " + HIC + "﹊_ ﹊" + CYN + "-  -▔﹊" + HIC + "_ ﹊   " + HIY + "|" + HIB + "▕▔ ▕      ▏\n" + NOR,
        "damage_type"		:	"可愛傷",
		"damage"			:	1200,
		"force"				:	150,
		"post_action"	:   (: delay :),
    ]),
//12
	([  "action" :
		"
			                                                                                
\t" + HBBLU + "    " + HIW + "○     " + HIR + "◣                    " + HIW + "○                    " + HIW + "○    " + HIG + "( /    " + NOR + "
\t" + HBBLU + "" + HIW + "○       " + HIR + "◣" + BLK + "。" + HIR + "◣    " + HIM + "藍 藍的一片～～好漂亮阿                   " + HIG + "\\ )╱" + HIW + "ｏ " + NOR + "
\t" + HBBLU + "  " + HIW + "o      " + HIR + "◤█◤             " + HIW + "o                          " + HIW + "。   " + HIG + "╲( " + NOR + "" + BBLU + "" + CYN + "▁▁" + NOR + "
\t" + HBBLU + "" + HIW + "。         " + HIR + "◤                 " + HIW + "。" + NOR + "" + BBLU + "" + CYN + "▁▁▂▂▃▃▄▄▅▅▆▆▇▇████\n" + NOR,
         "damage_type"       :	"可愛傷",
         "damage"			 :	1000,
         "force"			 :	100,
    ]),
//13

	([  "action" :
		"
      " + HBBLU + "" + HIY + "                ╲                      ╱         ★          " + HIW + "*     " + NOR + "
      " + HBBLU + "" + HIY + "       ╲              ☆                  ☆              ╱        " + NOR + "
      " + HBBLU + "" + HIY + "           " + HIC + "*       .                ☆               ☆              " + NOR + "
      " + HBBLU + "" + HIY + "         .            ☆        " + HIW + "☆     *        .  *                 " + NOR + "
      " + HBBLU + "" + HIY + "             ☆      .   *          *        .             " + HIC + "☆        " + NOR,


         "damage_type"       :	"美美傷",
         "damage"			 :	1000,
         "force"			 :	100,
    ]),

//14
	([  "action" :
		"
\t" + HIW + "████　" + HIC + "███　◢██◣█◣◢█◢██◤　" + HIR + "█▋██◢██◣█▋██
\t " + HIW + "███ 　" + HIC + "███　█▋███▋███▆▆▋　" + HIR + "█▋███▋███▋██
\t " + HIW + "███   " + HIC + "███　█▋███▋█████▋　" + HIR + "◥██◤█▋███▋██
\t" + HIW + "████　" + HIC + "████◥██◤◥██◤◥▆▆◣　　" + HIR + "██　◥██◤◥██◤ ● \n" + NOR,

         "damage_type"       :	"可愛傷",
         "damage"			 :	1000,
         "force"			 :	100,
    ]),
//15
	([  "action"  :
		"
                            (\\     /)
                            \\+++++++/
                           ＜| ^ ^ |＞      咩咩咩....^^
                              | . |
  咩咩可以吃草了!!          >- \\_/ ~~~~~)~~
                                 (______)
                                   V  V
                         ^^^^^^^^^^^^^^^^^^^^^^^  \n",
         "damage_type"       :	"可愛傷",
         "damage"			 :	1000,
         "force"			 :	100,
    ]),
//16
    ([  "action"  :
		"
\t           " + HIW + ".*★*★." + NOR + "             　　　　　    " + HIG + ".’  ’." + NOR + "
\t         " + HIW + "★        *.*★*★." + NOR + "    " + HBRED + "" + HIC + "累積多少思念*才能見妳一面?
" + NOR + " \t
\t        " + HIW + "★ " + HBMAG + "" + HIC + "思念妳" + NOR + "  " + HIW + "’       *" + HIG + "        .*    *’" + NOR + "
\t        " + HIW + "* " + HBMAG + "" + HIC + "就像光著腳" + NOR + "" + HIW + "        ★" + HIG + "        *☆.*’" + NOR + "
\t        " + HIW + "*  " + HBMAG + "" + HIC + "踩在滿地碎玻璃上" + NOR + "" + HIW + " ★" + HIG + "              .★*★." + NOR + "
\t        " + HIW + "‧   " + HBMAG + "" + HIC + "那麼痛" + NOR + "" + HIW + "        * " + HIG + "        .*★ *.*    ★" + NOR + "
\t        " + HIW + "‘  " + HBMAG + "" + HIC + "卻又躲不掉" + NOR + "" + HIW + "  .*’" + HIG + "         ★" + HBRED + "" + HIC + "思念無止盡" + NOR + " " + HIG + "*" + NOR + "
\t         " + HIW + "‘.          *’           " + HIG + "★ " + HBRED + "" + HIC + "見面無限期" + NOR + " " + HIG + ".’" + NOR + "
\t           " + HIW + " .     . ’               " + HIG + "‘*.   　  ." + NOR + "
\t            " + HIW + " .‧’                       " + HIG + "‘ ‧.’   \n" + NOR,

	     "damage_type"       :	"情傷",
         "damage"			 :	1000,
         "force"			 :	100,
		 "post_action"		 :  (: poem2 :),
    ]),
//17
	([  "action"  :
		"
\t" + HIC + "  ╭╠═════╮═╦══  ═╬═  ═══╝═╦═══
\t╭╯╯    ║    ╯╭╯╮╭╭╦╩══╭══╮╭╯══╮" + NOR + "" + HIW + "
\t" + BCYN + "║║   ║ ║ ║   ╭═╣╯╭╯══╮║    ║╠═══║" + NOR + "" + HIW + "
\t" + BCYN + "╯║ ╭╯ ║ ╰╮ ╭═╣╮╯╠══╣╰══╯╠═══║" + NOR + "" + HIC + "
\t  ║ ║   ║   ║ ╯  ║╰  ║    ║  ╮╭  ╰╦═╦╯
\t  ╯    ╰╯        ═╯    ╰══╯═╩╩══╯  ╰═  \n" + NOR,

	     "damage_type"       :	"豬頭傷",
         "damage"			 :	1000,
         "force"			 :	100,
    ]),
//18
	([  "action"  :
		"
\t			                                                                                
\t            、〝  〞  、 ’   爛
\t           、  ╭–╮〝╰○︿′  電
\t               ╰當╯ ‵︿）       腦
\t    .......′   [≡]     〈..........   ",


	     "damage_type"       :	"豬頭傷",
         "damage"			 :	1000,
         "force"			 :	100,
    ]),
//19
	([  "action"  :
		"
\t" + HIR + "     ╰══╮       ╭╭═════╮╭═══╩═══╮╭═══╩═══╯" + NOR + "
\t" + HIR + "    ══╮        ╭╯║          ║║  ║      ║  ║║ ═══╬══╬ " + NOR + "
\t" + HBRED + "" + HIW + "╰══╮║╭══╯║║╰══╦══╯══╬═══╬══║ ═══╬══╯" + NOR + "
\t" + HBRED + "" + HIW + "    ╭╯║╰╮    ╯║═══╬═══    ╰═╮═╯    ║ ╰═╮║╭═╯" + NOR + "
\t" + HIR + "╭═╯  ║  ╰═╮  ║╭╯  ║  ╰╮    ╭═╰═╮    ║╭═╯ ║ ╰═╮" + NOR + "
\t" + HIR + "        ╯          ╯      ╯        ╰╯      ╰╯  ╯       ╯\n" + NOR,
	     
         "damage_type"       :	"感傷",
         "damage"			 :	1000,
         "force"			 :	100,
		 "post_action"       :  (: poem3 :),
	]),
//20
	([  "action"  :
		"
\t" + HIW + "════╦════ ═╮╰═╮║╭═╯ ╭╦═════╦╯ ═╬═ ═════" + NOR + "
\t" + HIW + "╭═══╬═══╮   ╰    ╭╯╮       ║╭═╦═╯║   ╭╬╮╭╯╭╯╭╯" + NOR + "
\t" + BMAG + "" + HIW + "║╰═╮║╭═╯║ ═╮╰═╯  ╰═╯   ║╭═╬═╮║   ╠╬╣╰╮╰╮╰╮" + NOR + "
\t" + BMAG + "" + HIW + "   ══════      ╰╰═╮║╭═╯   ║║  ║  ║║   ╰╬╯ ══╦══ " + NOR + "
\t" + HIW + " ═╦══════    ╭    ╭╯╮       ║╰═╬═╯║   ═╬═     ║" + NOR + "
\t" + HIW + "   ╰════╣    ═╯╰═╯  ╰═╯ ╰╯══╩═╣╰╯   ╯   ══╩══\n" + NOR,

	     
         "damage_type"       :	"感傷",
         "damage"			 :	1000,
         "force"			 :	100,
		 "post_action"       :  (: poem3 :),
	]),
//21
	([  "action"  :
		"
\t" + HIC + "╭═══════╮════╩════╭═══════╮═╩═ ══╦══" + NOR + "
\t" + HIC + "╠═══════╣  ═══════  ╠═══════╣ ══  ══╬═╮" + NOR + "
\t" + BCYN + "" + HIW + "╰═══╦═══╯  ═══════  ╰═══╦═══╯ ══  ══╩═╩" + NOR + "
\t" + BCYN + "" + HIW + "╠═══╬═══  ╭═══════╮╠═══╬═══  ╭═╮ ╭═══╮" + NOR + "
\t" + HIC + "╯═══╬═══  ║              ║╯═══╬═══  ║  ║ ║      ║" + NOR + "
\t" + HIC + "════╩════╰═══════╯════╩════╰═╯ ╰═══╯\n" + NOR,
         "damage_type"       :	"感傷",
         "damage"			 :	1000,
         "force"			 :	100,
		 "post_action"       :  (: poem3 :),
	]),


});

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}


mapping query_action(object me, object weapon)
{
    mapping do_action;
    object *enemy, weaponn;
    string actionn;
    int i,j,kee,level,force_level;
    if(random(5) > 1 && me->query_skill("papa-sword",1) >= 150 && random(me->query("bellicosity")/500) > 10)
    {
        enemy = me->query_enemy(); 
        for(i=0;i<(sizeof(action)-random(15));i++)
        {
            for(j=0;j<sizeof(enemy);j++)
            {
                do_action = action[random(10)];  //此為計算連擊
                actionn = "\n";
                actionn += do_action["action"];
                if( weaponn=me->query_temp("weapon") )
                    actionn = replace_string(actionn, "$w", weaponn->name());
                message_vision(actionn, me, enemy[j]);
                
                if( random(me->query("combat_exp")) > random(enemy[j]->query("combat_exp"))/5
					||(random(me->query_cps())) > (random(enemy[j]->query_cps())+random(enemy[j]->query_kar()))/2) 
                {
                    kee = enemy[j]->query("eff_kee");
                    enemy[j]->receive_wound("kee", kee/60,me);
					message_vision(HIR + "\n$N閃躲不及，被趴趴劍法刺中了要害。\n" + NOR, enemy[j]);
                    COMBAT_D->report_status(enemy[j]);
                 }
                      else message_vision(HIY + "\n$N人比劍快，驚險地閃過了這一劍。\n" + NOR, enemy[j]);
             }
         }
         if( random(me->query_cps()) < 4 ) 
         {
             me->add("sen", -10);                
             tell_object(me,"\n你使了趴趴劍法奧義後，由於定力不夠，以致於精神無法集中。\n\n");
             me->start_busy(1);
          }
    }
//此部份為隨機出招部份
    level =(int)me->query_skill("papa-sword",1);
    force_level=(int)me->query_skill("papa-force",1);    
    if(level > 0  && level < 50 )
        return action[random(5)];
    if(level >= 50  && level < 100 )
        return action[random(7)];
    if(level >= 100  && level < 130 )
        return action[random(8)];
    if(level >= 130 && level < 150 )
        return action[random(10)];
    if(level >= 150 && level < 180 )
        return action[random(15)];
	if(level >=180 && force_level >= 200)
		return action[random(21)];
     return action[random(sizeof(action))];
}

void poem1(object me,object target,object weapon,int damage)
{
     int exp,power,time,i,j;
     exp = me->query("combat_exp");
     power = me->query("max_force")/10;
     time = me->query("MKS")/3000;
     if( time > 8) 
     time = 8;
if( me->query_skill("papa-sword",1) >= 150  && exp >= 3000000  && random(4)>1 )
 {         
   message_vision(HIW + "
\t        $N 大喝一聲　" + HIW + BBLU + "＜　" + HIC + "念　奴　嬌　" + HIW + "＞" + NOR + "" + HIW + "，剎那間四處黃沙爆起
		
\t\t        " + HIG + "蕭條庭院 又斜風細雨 重門須閉  

\t\t        寵柳嬌花寒食近 種種惱人天氣  

\t\t        險韻詩成 扶頭酒醒 別是閑滋味  

\t\t        鴻過盡 萬千心事難寄  

\t\t        樓上幾日春寒 簾垂四面 玉欄干慵倚  
 
\t\t        被冷香消新夢覺 不許\愁人不起

\t\t        清露晨流 新桐初引 多少遊春意  \n" + NOR,me);

   for(i=0;i<=time;i++)
      {  
        message_vision(HIW + "只見眼前雪花飄飄，$n呆在原地，任由無數劍氣穿刺而過。\n" + NOR,me,target);

        for(j=0;j<=random(time);j++)
         {
           target->receive_damage("kee",power);
           me->add("swordkee",-10);
           me->add("force",-time*10);
           COMBAT_D->report_status(target);
         }
      }
 }
}

void delay (object me, object target, object  weapon, int damage)
{
	int time=(random(me->query_kar()))/10+1;
	if (random((me->query("combat_exp"))*10) > random((target->query("combat_exp"))/5) &&
		random(me->query("max_force")) > random(target->query("max_force")))
		message_vision(HIW + "$n彷彿見到了自己的國小老師，攝於$N的威嚴，一動也不敢動！！\n" + NOR,me,target);
	    target->start_busy(time);
		return;
}

void poem2 (object me, object target, object  weapon, int damage)
{
	object *enemy;
	int i,j,k,hurt,time;
	enemy=me->query_enemy();
	i=sizeof(enemy);
    time=random(me->query("MKS")/5000)+1;
	hurt=random(15)*(me->query("combat_exp")/30000+me->query("MKS")/20+me->query("max_force")/100);
	if (me->query("combat_exp")>3000000 && me->query("MKS")>30000 && me->query("bellicosity")>15000)
	{
		message_vision(HIW + "$N突然深情地望著$n，娓娓地道出．．
  ～～　" + BBLU + "" + HIC + "十　六　句　之　愛　的　宣　言　" + NOR + "" + HIW + "～～ \n\n\n" + NOR,me,target);
		for (j=1;j<=time;j++)
		{
			switch(j)
			{
			case 1 :
				message_vision("\n
		" + BCYN + "" + HIW + "１見鐘情能不能相信？\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 2 :
				message_vision("\n
		" + HBMAG + "" + HIW + "２對情侶在我面前晃來晃去！\n" + NOR,me);
				k=random(sizeof(enemy));
				enemy[k]->receive_wound("kee",random(5)*hurt/2,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 3 :
				message_vision("\n
		" + HBRED + "" + HIW + "３朵玫瑰代表我愛你．．\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 4 :
				message_vision("\n
		" + BYEL + "" + HIW + "４分鐘的見面能回味一星期．．\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 5 :
				message_vision("\n
		" + BWHT + "" + HIB + "５年的喜歡算不算專情？？\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 6 :
				message_vision("\n
		" + HBBLU + "" + HIC + "６封沒寫地址的信鎖在抽屜～\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 7 :
				message_vision("\n
		" + HBGRN + "" + HIW + "７週見一次面的戀情淒不淒迷！\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 8 :
				message_vision("\n
		" + HBBLU + "" + HIW + "８杯長島冰茶灌不醉伐燙的心。\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 9 :
				message_vision("\n
		" + HBYEL + "" + HIR + "９件毛衣擋不住身邊沒有你的寒意．．\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 10 :
				message_vision("\n
		 " + HBRED + "" + HIC + "１０種想你的難熬漫漫無期．．\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 11 :
				message_vision("\n
		" + HBMAG + "" + HIG + "１１本日記全都寫你！！\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 12 :
				message_vision("\n
		" + HBRED + "" + HIM + "１２個月的相思不斷繼續．．．\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 13 :
				message_vision("\n
		" + HBBLU + "" + HIR + "１３名追求者懶得去理～\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 14 :
				message_vision("\n
		" + HBMAG + "" + HIY + "１４日的約會不能忘記！！\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 15 :
				message_vision("\n
		" + HBGRN + "" + HIB + "１５句我愛你夠不夠誠意？？\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			case 16 :
				message_vision("\n
		" + BMAG + "" + HIC + "１６顆金莎不會太膩！！\n" + NOR,me);
			    k=random(sizeof(enemy));
			    enemy[k]->receive_wound("kee",hurt,me);
				COMBAT_D->report_status(enemy[k]);
				break ;
			}
		}
	}
}

void poem3 (object me, object target, object  weapon, int damage)
{
	//object *enemy;
	int time,lv,i,j,hurt,k,bell,intt,conn,karr;
	lv=me->query_skill("papa-sword",1);
	bell=me->query("bellicosity",1);
	intt=me->query_int();
	conn=me->query_con(1);
	karr=me->query_kar();
	//enemy=me->query_enemy();
    //k=sizeof(enemy);
	//j=random(sizeof(enemy));
	hurt=random(me->query("max_force",1)/1000 + me->query("MKS",1)/50);
	time=(random((intt+conn+karr)/30+1)+random(lv/30))*2;
	if (time > 8)
	{time = 8;}

	if ( (random(conn) + random(karr) + random(intt))* 500000 > target->query("combat_exp",1))
	{
		message_vision("\n
	" + HIC + "$N有感於古人李商隱的情操，因而隨口誦出了古詩．．

    \t\t        " + HIW + "【 　" + HIY + "無　　題　 " + HIW + "】" + NOR + "\n\n",me);

		for (i=0;i<=time;i++)
		{
			switch(i)
			{
			case 1 :
				message_vision("\n\n\t\t" + HIY + "《　" + BWHT + "" + BLK + "相　見　時　難　別　亦　難" + NOR + "　" + HIY + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 2 :
				message_vision("\n\n\t\t" + HIG + "《　" + HBRED + "" + HIW + "東　風　無　力　百　花　殘" + NOR + "　" + HIG + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 3 :
				message_vision("\n\n\t\t" + HIR + "《　" + HBGRN + "" + HIW + "春　蠶　到　死　絲　方　盡" + NOR + "　" + HIR + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 4 :
                message_vision("\n\n\t\t" + HIM + "《　" + HBYEL + "" + HIW + "蠟　炬　成　灰  淚\　始　乾" + NOR + "　" + HIM + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 5 :
				message_vision("\n\n\t\t" + HIC + "《　" + HBMAG + "" + HIW + "曉　鏡　但　愁　雲　鬢　改" + NOR + "　" + HIC + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 6 :
				message_vision("\n\n\t\t" + HIW + "《　" + HBBLU + "" + HIW + "夜　吟　應　覺　月　光　寒" + NOR + "　" + HIW + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 7 :
				message_vision("\n\n\t\t" + HIB + "《　" + HBCYN + "" + HIW + "蓬　萊　此　去　無　多　路" + NOR + "　" + HIB + "》" + NOR + "\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			case 8 :
				message_vision("\n\n\t\t《　" + BBLK + "" + HIW + "青　鳥　殷　勤　為　探　看" + NOR + "　》\n",me);
				message_vision(HIW + "\n\n$N臉上夾帶著暴戾之氣，往$n身上連刺數劍，快意不絕！\n" + NOR,me,target);
				if (me->query("max_force",1) > target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIR + "$n一時不知所措，任由$N在其身上恣意砍殺，血流不止\n" + NOR,me,target);
					target->receive_wound("kee",hurt,me);
					COMBAT_D->report_status(target);
				}
				else if (me->query("max_force",1) < target->query("max_force",1) && random(10) > 1)
				{
					message_vision(HIC + "$n憑著深厚的內力抵擋了$N強大的攻擊！\n" + NOR,me,target);
					target->receive_wound("kee",random(3)*(hurt/100),me);
					COMBAT_D->report_status(target);
				}
				else 
				{
					message_vision(HIM + "$N在驚嚇之餘，連忙地連滾帶爬逃了開來。\n" + NOR,target);
				}
				break ;
			}
		}
	}
}




