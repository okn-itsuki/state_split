# state_split

Error Handling

1) _EINVAL
	[aa bb "cc]など無効な引き数が渡された場合、エラー出力してNULLを返す。
2) _ENOMEM
malloc確保失敗時に途中まで確保されたメモリをfreeかつ、エラー出力してNULLを返す。