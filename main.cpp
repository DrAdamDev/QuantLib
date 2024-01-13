#include <ql/quantlib.hpp>

using namespace QuantLib;

int main() {

	try {

		// Set up the QuantLib date settings (optional, if needed)
		Settings::instance().evaluationDate() = Date(13, January, 2024);

		// Define market data
		Real underlyingPrice = 100.0; // Current asset price (S)
		Real strikePrice = 105.0; // Strike price (K)
		Rate riskFreeRate = 0.03; // Risk-free interest rate (r)
		Rate dividendYield = 0.0; // Dividend yield (q) if applicable
		Volatility volatility = 0.2; // Volatility (ô)

		// Output market data

		// Define the option
		Option::Type optionType = Option::Call; // Call option
		Date expirationDate(13, April, 2024); // Expiration date (13th April 2024)

		// Output option data
		return 0;
		
	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
