#include <iostream>
#include <ql/quantlib.hpp>

using namespace QuantLib;

int main() {
    try {
        // Define a simple interest rate swap
        Calendar calendar = TARGET();
        Date today = Date(15, January, 2024);
        Settings::instance().evaluationDate() = today;
        Date settlementDate = calendar.advance(today, 2, Days);
        Date maturity = calendar.advance(settlementDate, 5, Years);
        Period fixedLegTenor = 6 * Months;
        Period floatingLegTenor = 3 * Months;
        Real notional = 1000000.0;
        Rate fixedRate = 0.02;
        Spread spread = 0.01;
        DayCounter fixedLegDayCounter = Actual360();
        DayCounter floatingLegDayCounter = Actual360();

        // Create yield curve for the floating leg (Euribor3M)
        Handle<YieldTermStructure> euriborTermStructure(
            ext::shared_ptr<YieldTermStructure>(new FlatForward(settlementDate, 0.02, Actual360()))
        );

        // Create the Euribor3M index with the term structure
        ext::shared_ptr<IborIndex> index(new Euribor3M(euriborTermStructure));

        Date startDate = calendar.advance(settlementDate, 1, Days);
        Schedule fixedSchedule(startDate, maturity, fixedLegTenor, calendar,
                               ModifiedFollowing, ModifiedFollowing,
                               DateGeneration::Forward, false);
        Schedule floatingSchedule(startDate, maturity, floatingLegTenor, calendar,
                                  ModifiedFollowing, ModifiedFollowing,
                                  DateGeneration::Forward, false);
        VanillaSwap swap(VanillaSwap::Payer, notional,
                         fixedSchedule, fixedRate, fixedLegDayCounter,
                         floatingSchedule, index, spread,
                         floatingLegDayCounter);

        // Set the term structure in the Euribor3M index
        index->addFixing(settlementDate, 0.02); // Initial fixing (replace with actual data if available)

        // Set the term structure for discounting
        Handle<YieldTermStructure> discountingTermStructure(
            ext::shared_ptr<YieldTermStructure>(new FlatForward(settlementDate, 0.02, Actual360()))
        );

        // Set the term structures in the QuantLib objects
        swap.setPricingEngine(ext::shared_ptr<PricingEngine>(
            new DiscountingSwapEngine(discountingTermStructure)
        ));

        // Calculate the fair price of the swap
        Real NPV = swap.NPV();
        std::cout << "Swap NPV: " << NPV << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
