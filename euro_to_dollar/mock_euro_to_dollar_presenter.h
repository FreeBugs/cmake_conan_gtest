class Mockeuro_to_dollar_presenter : public euro_to_dollar_presenter {
 public:
  MOCK_METHOD(void, set_view, (euro_to_dollar_view *view), (override));
  MOCK_METHOD(void, set_model, (euro_to_dollar_calculator *model), (override));
  MOCK_METHOD(void, rechnen, (), (const, override));
  MOCK_METHOD(void, beenden, (), (const, override));
  MOCK_METHOD(void, populate_items, (), (const, override));
  MOCK_METHOD(void, update_rechnen_action_state, (), (const, override));
};
