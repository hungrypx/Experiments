#include "pch.h"
#include "..\ConsoleApplication1\WeatherBoard.h"
#include "gmock\gmock.h"
using ::testing::_;
using ::testing::Return;

    class WeatherMock : public Weather
	{
	public:
		MOCK_METHOD1(RetrieveWeatherThroughUrl, std::string(std::string url));
		MOCK_METHOD0(GetCurrentTime,std::time_t());
	};

	TEST(CWeatherBoardTest, TestWeather_UPDATE_SUNNY)
	{
		WeatherMock mock;
		ON_CALL(mock, RetrieveWeatherThroughUrl(_)).WillByDefault(Return("SUNNY"));
		time_t t;
		time(&t);
		ON_CALL(mock, GetCurrentTime()).WillByDefault(Return(t));
		CWeatherBoard board(&mock);
		board.UpdateWeather(nullptr);
		auto w = board.GetWeather();

		ASSERT_EQ("SUNNY", w);
	}
	TEST(CWeatherBoardTest, TestWeather_NOT_UPDATE_EXPECT_UNKNOWN)
	{
		WeatherMock mock;
		time_t t;
		time(&t);
		struct tm tmStruct ; 
		localtime_s(&tmStruct,&t);
		tmStruct.tm_hour = 9;
		t = mktime(&tmStruct);
		ON_CALL(mock, RetrieveWeatherThroughUrl(_)).WillByDefault(Return("SUNNY"));
		ON_CALL(mock, GetCurrentTime()).WillByDefault(Return(t));
		CWeatherBoard board(&mock);
		board.UpdateWeather(nullptr);
		auto w = board.GetWeather();
		ASSERT_EQ("UNKNOWN", w);

	}