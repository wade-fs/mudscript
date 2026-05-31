#pragma save_binary

// 本檔案是 TMI-2 的一部份, 如果您要使用本檔案, 請保留本說明
// 本檔由 Buddha@TMI 所寫, modularized and revised (92-05-01)
// 由 Buddha (92-05-31) 增加保密系統 PS: 由 Annihilator 拿掉了
// 暫時性的變數由 Watcher (93-02-21) 所寫
// 由 Pallando @ Tabor (93-03-17) 改寫過
// 把 _set() 的傳回值改為所設定的值, 由 Annihilator (95-03-15) 改寫
// NB these functions don't have to be nomask if you prevent objects shadowing
// them in the same circumstances that shadowing query is not allowed.
// 由 wade@Fantasy.Space 改寫, 將遞迴改成非遞迴, 增加速度. (1996-6-2)

static nomask /* private */ mixed _query (mapping map, string *parts)
{
  mixed value;
  int i;

  value = map;
  for (i=0 ; i < sizeof(parts); i++) {
    if (undefinedp (value = value[parts[i]]))
      break;
    if( !mapp (value))
      break;
  }
  return value;
}

// 將遞迴改成非遞迴, by wade@Fantasy.Space 1996/6/2
static nomask /* private */ int _delete (mapping map, string *parts)
{
  mixed value;
  int i;

  value = map;
  for (i=0; i<sizeof(parts)-1; i++) {
    if (undefinedp (value=value[parts[i]]))
      return 0;
    if (!mapp(value))
      return 0;
  }
  if (!mapp(value))
    return 0;
  map_delete(value, parts[i]);
  return 1;
}

// 把遞迴改成非遞迴, 由 wade@Fantasy.Space 所改寫 (1996/6/2)
static nomask /* private */ mixed _set (mapping map, string *parts, mixed value)
{
  mixed sub;
  int i;

  sub = map;
  for (i=0; i<sizeof(parts)-1; i++) {
    if (!sub[parts[i]] || !mapp (sub[parts[i]]))
      sub[parts[i]] = ([ parts[i+1] : 0 ]);
    sub = sub[parts[i]];
  }
  return sub[parts[i]] = value;
}
