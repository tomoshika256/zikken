# include <Siv3D.hpp>

void Main()
{
	Window::Resize(1280, 720);

	Scene::SetBackground(Palette::Darkgreen);

	// カードの幅が 75 ピクセルで裏面が赤色のカードパックを作成
	const PlayingCard::Pack pack{ 75, Palette::Red };

	// ジョーカーの枚数
	constexpr int32 NumJokers = 2;

	// 52 枚 + ジョーカーを含むカードを作成する
	Array<PlayingCard::Card> cards = PlayingCard::CreateDeck(NumJokers);

	while (System::Update())
	{
		for (size_t i = 0; i < cards.size(); ++i)
		{
			const Vec2 center{ (100 + i % 13 * 90), (100 + (i / 13) * 130) };

			if (pack.regionAt(center).mouseOver())
			{
				Cursor::RequestStyle(CursorStyle::Hand);

				if (MouseL.down())
				{
					// カードをめくる
					cards[i].flip();
				}
			}

			// カードを描画する
			pack(cards[i]).drawAt(center);
		}
	}
}
