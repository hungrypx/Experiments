#pragma once
#include <string>
#include <ctime>

    class Weather
	{
	public:
		virtual std::string RetrieveWeatherThroughUrl(std::string url);
		virtual std::time_t GetCurrentTime();
	};

	class CLocation
	{
	public:
		std::string GetLocation();
	};

	class CWeatherBoard
	{
	public:
		CWeatherBoard(Weather* pw);
		void UpdateWeather(CLocation* ploc);

		std::string GetWeather();

	private:
		std::time_t GetSystemCurrentTime();
		void UpdateWeatherFromInternet(CLocation* ploc);

	private:
		Weather* m_pWeather;
		std::string weather;
	};