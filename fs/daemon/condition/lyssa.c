// lyssa.c 狂犬病 by babe
// mob  set( "no_lyssa", 1 ); 此 mob 免疫
// room set( "no_lyssa", 1 ); 此 room 為免疫區
// 若需修改, 請 post 告知 ACKY, thx..

#include <ansi.h>

int update_condition( object me, int duration )
{
	int i, bell;
	object *inv;
	
	me->apply_condition( "lyssa", duration - 1 );

     if( 1 ) {
         me->clear_condition("lyssa");
		message_vision( HIW"$N突然不停地顫抖, $N的狂犬病痊癒了。\n"NOR, me );
		return 0;
        }

	if( environment(me)->query("no_lyssa")==1 )
		return 1;

	inv = all_inventory(environment(me));

	switch( random(5) ) {
	case  0 :
		EMOTE_D->do_emote( me, "bite", inv[random(sizeof(inv))]->query("id") );
		break;
	case  1 :
		EMOTE_D->do_emote( me, "dog" );
		break;
	case  2 :
		tell_room( environment(me), HIR + me->query("name") + "不停地滴口水, 你在" + me->query("name") + "的眼裡, 似乎是根美味的大骨頭。\n"NOR, me );
		break;
	case  3 :
		tell_room( environment(me), HIR + me->query("name") + "朝著你狂吠, 似乎想把你給撕裂一般。\n"NOR, me );
		break;
	default :
		message_vision( HIR"$N流著口水, 嗤牙咧嘴的, 顯然是狂犬病發作了。\n"NOR, me );
	}

	// 注意! 程式有點小複雜, { } 弄錯的話, 邏輯上會有很大的差異!
	for( i=0; i<sizeof(inv); i++ )
		// 狂犬病處理對象: 1.不是自己 2.不是wiz 3.活著
		if( inv[i]!=me && !wizardp(inv[i]) && living(inv[i]) ) {

			// 狂犬病傳染對象: 1.沒有帶原 2.愈多人在一起愈不容易被傳染
			if( !inv[i]->query_condition("lyssa") && random(sizeof(inv))==1 )
				// no_lyssa 者免疫
				if( inv[i]->query( "no_lyssa" ) )
					if( random(2) ) {
						message_vision( HIR"$N狠狠地咬了$n一口!\n\n"NOR
								   "$n驚道: 糟了, 是狂犬病!\n"
								CYN"$n趕緊運起天邪神功\, 體內不斷冒出陣陣黑氣。\n"NOR, me, inv[i] );
						if( inv[i]->query("force") >= 100 )
							inv[i]->add( "force", -100 );
						else
							inv[i]->set( "force",    0 );
						tell_object( inv[i], "你成功\地逼出狂犬病之病毒。\n" );
					}
					else
						message_vision( HIR"$N突然瘋狂地撲向$n!\n\n"NOR
								   "$n輕輕一閃, 結果$N撲了空, 跌個狗吃屎。\n\n"
								CYN"$n笑道: 就憑這麼笨拙的身法也想咬我, 哈～\n"NOR, me, inv[i] );
				// 傳染成功
				else {
					message_vision( HIR"$N狠狠地咬了$n一口, $n被傳染了狂犬病。\n"NOR, me, inv[i] );
					if( me->query_condition("lyssa")*2 > 200 )
						inv[i]->apply_condition( "lyssa", 200 );
					else
						inv[i]->apply_condition( "lyssa", me->query_condition("lyssa")*2 );
				}

			// 咬人(fight)
			bell = me->query("bellicosity");
			bell = bell/1000 + 10;
			if( bell > 50 )
				bell = 50;
			if( random(100) < bell						&& // 咬人機率(10%~50%)
			    !environment(me)->query("no_fight") 			&& // 可以fight 
			    !(!userp(me)&&!userp(inv[i])) 				&& // mob不互咬 
			    me->query("combat_exp")*2 > inv[i]->query("combat_exp") 	&& // 被咬對象之EXP介於 
			    me->query("combat_exp")/2 < inv[i]->query("combat_exp") 	&& // 自己(0.5~2)倍之間
			    !me->is_fighting(inv[i]) ) {				   // 非fight狀態
				message_vision( HIR"$N突然瘋狂地撲向$n!\n"NOR, me, inv[i] );
				me->fight_ob(inv[i]);
			}

		}			

	return 1;
}

